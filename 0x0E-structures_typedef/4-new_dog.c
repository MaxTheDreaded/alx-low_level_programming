#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;
int i, j, k, l;

if (name == NULL || owner == NULL)
return (NULL);

for (i = 0; name[i] != '\0'; i++)
;
for (j = 0; owner[j] != '\0'; j++)
;

new_dog = malloc(sizeof(dog_t));
if (new_dog == NULL)
return (NULL);

new_dog->name = malloc(sizeof(char) * (i + 1));
if (new_dog->name == NULL)
{
free(new_dog);
return (NULL);
}
for (k = 0; k < i; k++)
new_dog->name[k] = name[k];
new_dog->name[k] = '\0';

new_dog->age = age;

new_dog->owner = malloc(sizeof(char) * (j + 1));
if (new_dog->owner == NULL)
{
free(new_dog->name);
free(new_dog);
return (NULL);
}
for (l = 0; l < j; l++)
new_dog->owner[l] = owner[l];
new_dog->owner[l] = '\0';

return (new_dog);
}
