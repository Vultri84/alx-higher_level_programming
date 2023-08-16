#include <stdio.h>
#include <stdlib.h>

/* Definition of singly linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function to check if a singly linked list is a palindrome */
int is_palindrome(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL)
        return 1;

    listint_t *crawl = *head;
    listint_t *fire = *head;
    listint_t *prev_crawl = NULL;
    listint_t *trunc = NULL;
    int is_palindrome = 1;

    while (fire != NULL && fire->next != NULL) {
        fire = fire->next->next;
        prev_crawl = crawl;
        crawl = crawl->next;
    }

    /* Odd number of elements, skip the middle node */
    if (fire != NULL) {
        crawl = crawl->next;
    }

    trunc = crawl;
    prev_crawl->next = NULL;

    /* Reverse the second half of the linked list */
    listint_t *present = trunc;
    listint_t *prev = NULL;
    listint_t *next = NULL;

    while (present != NULL) {
        next = present->next;
        present->next = prev;
        prev = present;
        present = next;
    }
    trunc = prev;

    /* Compare the first half and reversed second half */
    listint_t *tempo1 = *head;
    listint_t *tempo2 = trunc;

    while (tempo1 != NULL && tempo2 != NULL) {
        if (tempo1->n != tempo2->n) {
            is_palindrome = 0;
            break;
        }
        tempo1 = tempo1->next;
        tempo2 = tempo2->next;
    }

    /* Restore the linked list to its original state */
    present = trunc;
    prev = NULL;
    while (present != NULL) {
        next = present->next;
        present->next = prev;
        prev = present;
        present = next;
    }
    trunc = prev;
    prev_crawl->next = trunc;

    return is_palindrome;
}

/* Example usage */
int main(void) {
    listint_t *head = NULL;
    
    /* Create a sample linked list (1 -> 2 -> 2 -> 1) */
    listint_t *node1 = malloc(sizeof(listint_t));
    listint_t *node2 = malloc(sizeof(listint_t));
    listint_t *node3 = malloc(sizeof(listint_t));
    listint_t *node4 = malloc(sizeof(listint_t));
    
    node1->n = 1; node1->next = node2;
    node2->n = 2; node2->next = node3;
    node3->n = 2; node3->next = node4;
    node4->n = 1; node4->next = NULL;
    
    head = node1;

    /* Call the is_palindrome function and print the result */
    int result = is_palindrome(&head);
    printf("Is the linked list a palindrome? %s\n", result ? "Yes" : "No");

    /* Free memory */
    while (head != NULL) {
        listint_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
