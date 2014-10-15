// Structs and Pointers To Them
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who) {
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who) {
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    struct Person *joe = Person_create("Joseph Puzzo", 20, 66, 130);
    struct Person *sam = Person_create("Samuel Harada", 19, 62, 140);
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Sam is at memory location %p:\n", sam);
    Person_print(sam);

    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    sam->age += 20;
    sam->weight +=  20;
    Person_print(sam);

    Person_destroy(joe);
    Person_destroy(sam);

    return 0;
}
