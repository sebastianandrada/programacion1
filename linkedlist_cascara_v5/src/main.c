/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../testing/inc/Employee.h"
static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1001,2000,1002,3000,4000,8000};
static float salarySortedUp[] = {8000,4000,3000,2000,1002,1001};
static int id[] = {11,20,3,4,9,99};

int main(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[6];

    list = ll_newLinkedList();
    for(i=0; i < 6; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        //printEmployee(pAux[i]);
        ll_add(list,pAux[i]);
    }

    printf("********************funcion map********\n");
    ll_map(list, printEmployee2);

    printf("*****************aumento sueldo***************\n");
    ll_map(list, aumentarSalarioEn5000);

    printf("********************funcion map********\n");
    ll_map(list, printEmployee2);

        /*startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort */

        /*
            ll_startIter()
            ll_getNext()
            accede con flecha al siguiente elemento
        */


    return 0;
}

































