#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
/**********************************************************************/
/**********************************************************************/

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) 
{
    return document[n-1][m-1][k-1];
}

/**********************************************************************/

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) 
{ 
    return document[m-1][k-1];
}

/**********************************************************************/

char*** kth_paragraph(char**** document, int k) 
{
    return document[k-1];
}

/**********************************************************************/

char* get_word(char* text, int start, int end) 
{
    
    int w_indx = 0 ;
    
    /*
        - if the string == "Ali" so its size equals to 4 bytes.
        - 3 of them are for 'A', 'l' and 'i' the fourth one is for the '\0'.
        - The string starts from index 0 and ends at index 2.
        - So, if we want to add two to the difference between 
        the end and the start, to get the actual size of the string to allocate.
    */
    char* word = calloc( end - start + 2, sizeof(char) ) ;
    
    for( int i = start; i <= end; i++ )
    {
        
        word[w_indx] = text[i] ;
        
        w_indx++ ;
        
    }
    
    /* Adding the NULL char at the end of each */
    word[w_indx] = '\0' ;

    return word ;
    
}

/**********************************************************************/

char** get_sentence(char* text, int start, int end) 
{
    
    char** sentence ;
    
    int word_cntr   = 1     ;
    int i           = start ;
    int s_indx      = 0     ;
    int w_start     = start ;
    
    for( int j = start; j <= end; j++ )
    {
        
        if( text[j] == ' ' )
        {
            word_cntr++ ;
        }
        else 
        {
        
        }
        
    }
    
    sentence = calloc( word_cntr, sizeof(char *) ) ;
  
    for( i = start; i <= end; i++ )
    {
        
        if( text[i] == ' ' )
        {
            
            /* The sentence ends before the '.' char by one index */
            sentence[s_indx] = get_word( text, w_start, i - 1 ) ;
            
            s_indx++ ;
            
            /* The next sentence start index */
            w_start = i + 1 ;
            
        }
        else 
        {
        
        }
        
    }
  
    /* Adding the last word to the sentence */
    sentence[s_indx] = get_word( text, w_start, i - 1 ) ;
  
    return sentence ;
    
}

/**********************************************************************/

char*** get_paragraph(char* text, int start, int end) 
{
    
    char*** paragraph ;
   
    int sentence_cntr   = 1     ;
    int i               = start ;
    int p_indx          = 0     ;
    int s_start         = start ;
    
    for( int j = start; j <= end; j++ )
    {
        
        if( text[j] == '.' )
        {
            sentence_cntr++ ;
        }
        else 
        {
        
        }
        
    }
    
    paragraph = calloc( sentence_cntr, sizeof(char **) ) ;
    
    for( i = start; i <= end; i++ )
    {
        
        if( text[i] == '.' )
        {
            
            /* The sentence ends before the '.' char by one index */
            paragraph[p_indx] = get_sentence( text, s_start, i - 1 ) ;
            
            p_indx++ ;
            
            /* The next sentence start index */
            s_start = i + 1 ;
            
        }
        else 
        {
        
        }
        
    }
    
    return paragraph ;
    
}

/**********************************************************************/

char**** get_document(char* text) 
{

    char **** docx ;
    
    int paragraph_cntr  = 1 ;
    int i               = 0 ;
    int d_indx          = 0 ;
    int p_start         = 0 ;
    
    for( int j = 0; text[j] != '\0'; j++ )
    {
        
        if( text[j] == '\n' )
        {
            paragraph_cntr++ ;
        }
        else 
        {
        
        }
        
    }
        
    docx = calloc( paragraph_cntr, sizeof(char***) ) ;

    for( i = 0; text[i] != '\0'; i++ )
    {
        
        if( text[i] == '\n' )
        {
            
            /* The paragraph ends before the '\n' char by one index */
            docx[d_indx] = get_paragraph( text, p_start, i - 1 ) ;
            
            d_indx++ ;
            
            /* The next paragraph start index */
            p_start = i + 1 ;
            
        }
        else 
        {
        
        }
        
    }
    
    /* Adding the last paragraph to the document */
    docx[d_indx] = get_paragraph( text, p_start, i - 1 ) ;
    
    return docx ;

}

/**********************************************************************/
/**********************************************************************/

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}