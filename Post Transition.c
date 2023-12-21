#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PACKAGE_NAME_MAX_LENGTH 6
#define TOWN_NAME_MAX_LENGTH    6


typedef struct {
    char* id;
    int weight;
} Package;

typedef struct {
    int min_weight;
    int max_weight;
    Package* packages;
    int packages_count;
} PostOffice;

typedef struct {
    char* name;
    PostOffice* offices;
    int offices_count;
} Town;


Package create_package() {
    
    Package package;
    
    package.id = (char*)malloc(PACKAGE_NAME_MAX_LENGTH * sizeof(char));
    
    scanf("%s\n%d", package.id, &package.weight);
    
    return package;
}

PostOffice create_post_office() {
    
    PostOffice post_office;
    
    scanf("%d %d %d", &post_office.packages_count,
                      &post_office.min_weight,
                      &post_office.max_weight);
    
    post_office.packages = (Package*)malloc((post_office.packages_count + 50) * sizeof(Package));
    
    return post_office;
}

Town create_town() {
    
    Town town;
    
    town.name = (char*)malloc(TOWN_NAME_MAX_LENGTH * sizeof(char));
    
    scanf("%s", town.name);
    scanf("%d", &town.offices_count);
    
    town.offices = (PostOffice*)malloc(town.offices_count * sizeof(PostOffice));
    
    return town;
}

void send_all_acceptable_packages(const Town* source, const int source_office_index,
                                        Town* target, const int target_office_index);
void add_package_to_office(PostOffice* office, const Package package);
Town* town_with_most_packages(const Town* towns, const int towns_count);
Town* find_town(const Town* towns, const int towns_count, const char* town_name);
bool is_package_acceptable(const PostOffice* target_office, const Package* package);
void print_all_packages(const Town* town);

// ----------------- .h file above -----------------

void send_all_acceptable_packages(const Town* source, const int source_office_index,
                                        Town* target, const int target_office_index) 
{   
    PostOffice* target_office = &target->offices[target_office_index];
    Package current_package;
    
    int source_office_packages = source->offices[source_office_index].packages_count;
    Package* new_office_packages = (Package*)malloc(source_office_packages*10 * sizeof(Package));
    int new_office_packages_count = 0;
    
    for (int package=0; package < source_office_packages; package++) {
        current_package = source->offices[source_office_index].packages[package];
        
        if (is_package_acceptable(target_office, &current_package)) {
            add_package_to_office(target_office, current_package);
            
        } else {
            new_office_packages[new_office_packages_count] = current_package;
            new_office_packages_count++;
        }
    }
    
    target_office = NULL;

    source->offices[source_office_index].packages_count = new_office_packages_count;
    source->offices[source_office_index].packages = new_office_packages;
}


void add_package_to_office(PostOffice* office, const Package package) {
    
    int packages_in_office = office->packages_count;
    
    office->packages[packages_in_office] = package;
    office->packages_count++;
}


Town* town_with_most_packages(const Town* towns, const int towns_count) {
    
    Town* town_with_most_packages = NULL;
    int max_packages = 0;
    int packages_in_town;
    int offices_count;
    
    for (int town=0; town < towns_count; town++) {
        packages_in_town = 0;
        offices_count = towns[town].offices_count;
        
        for (int office=0; office < offices_count; office++) {
            packages_in_town += towns[town].offices[office].packages_count;
        }
        
        if (packages_in_town > max_packages) {
            town_with_most_packages = &towns[town];
            max_packages = packages_in_town;
        }        
    }
    
    return town_with_most_packages;
}


Town* find_town(const Town* towns, const int towns_count, const char* town_name) {
    
    for (int town=0; town < towns_count; town++) {        
        if (!strcmp(towns[town].name, town_name)) {
            return &towns[town];
        }
    }

    return NULL;
}


bool is_package_acceptable(const PostOffice* target_office, const Package* package) {            

    return package->weight >= target_office->min_weight &&
           package->weight <= target_office->max_weight;
}


void print_all_packages(const Town* town) {
    
    printf("%s:\n", town->name);
    
    for (int office=0; office < town->offices_count; office++) {
        printf("\t%d:\n", office);
        
        for (int package = 0; package < town->offices[office].packages_count; package++) {
            printf("\t\t\%s\n", town->offices[office].packages[package].id);
        }
    }
}


int main() {
    int towns_count;
    int offices_count;
    int packages_count;
    
    Town* source_town = NULL;
    Town* target_town = NULL;
    char target_town_name[TOWN_NAME_MAX_LENGTH];
    char source_town_name[TOWN_NAME_MAX_LENGTH];
    int target_index;
    int source_index;
    int queries_count;
    int query_type;
    
    scanf("%d", &towns_count);
    
    Town* towns = (Town*)malloc(towns_count * sizeof(Town));
    
    for (int town = 0; town < towns_count; town++) {    
        towns[town] = create_town();   
        offices_count = towns[town].offices_count;

        for (int office=0; office < offices_count; office++) {
            towns[town].offices[office] = create_post_office();        
            packages_count = towns[town].offices[office].packages_count;
            
            for (int package=0; package < packages_count; package++) {
                towns[town].offices[office].packages[package] = create_package();
            }
        }
    }
        
    scanf("%d", &queries_count);
    
    while (queries_count--) {
        scanf("%d", &query_type);
        
        switch (query_type) {
            case 1:
                scanf("%s", source_town_name);
                
                source_town = find_town(towns, towns_count, source_town_name);
                print_all_packages(source_town);
                
                break;
            case 2:
                scanf("%s %d", source_town_name, &source_index);
                scanf("%s %d", target_town_name, &target_index);
                
                source_town = find_town(towns, towns_count, source_town_name);
                target_town = find_town(towns, towns_count, target_town_name);
                
                send_all_acceptable_packages(source_town, source_index,
                                             target_town, target_index);
                
                break;
            case 3:
                printf("Town with the most number of packages is %s\n", 
                       town_with_most_packages(towns, towns_count)->name);
                       
                break;
        }
    }
 
    return EXIT_SUCCESS;
}
