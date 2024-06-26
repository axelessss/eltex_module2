#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#define N 50

int main()
{
    Contact contact;
    btree *root = NULL;
    int action;
    char surname[N];
    char name[N];
    //printf("%d", strcmp("Овчинников", "Иванов"));
    while (true)
    {
        printf("\nДобро пожаловать в список контактов! Выберите желаемое действие:\n1-добавить контакт\n2-редактировать контакт\n3-удалить контакт\n4-очистить список\n5-просмотр контакта\n6-просмотр списка контактов\n");
        printf("Для закрытия программы нажмите любую другую кнопку\n");
        scanf("%d", &action);

        switch(action)
        {
            case 1:
                add(&contact);
                Ins_Btree(&contact, &root);
                break;

            case 2:
                printf("Введите фамилию контакта, который хотите отредактировать: ");
                scanf("%s", surname);

                printf("Введите имя контакта, который хотите отредактировать: ");
                scanf("%s", name);

                Change_Contact(surname, name, &root);
                break;
            
            case 3:
                printf("Введите фамилию контакта, который хотите удалить: ");
                scanf("%s", surname);

                printf("Введите имя контакта, который хотите удалить: ");
                scanf("%s", name);

                printf("%d", Delete(surname, name, &root));

                break;

            case 4:
                Delete_Tree(&root);
                break;
            
            case 5:
                printf("Введите фамилию контакта, который хотите просмотреть: ");
                scanf("%s", surname);

                printf("Введите имя контакта, который хотите просмотреть: ");
                scanf("%s", name);

                
                Print_Contact(surname, name, &root);
                break;

            case 6:
                Print_Btree(root);
                printf("\n");
                break;

            default:
                return 0;
        }
    }
}