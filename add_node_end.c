
#include "holberton.h"
/**
 * add_node_end - adds a node to linked list from the end node
 * @head: double pointer to head node
 * @str: pointer to string
 *
 * Return: return pointer to the new node, NULL if fail
 */
list_t *add_node_end(list_t **head, char *str)
{
list_t *current;

current = *head;
if (str == NULL || head == NULL)
return (NULL);
if (current == NULL)
{
(*head) = add_node(head, str);
}
else
{
while (current->next != NULL)
current = current->next;
current = add_node(&(current->next), str);
}
return ((*head));
}
