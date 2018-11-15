#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

int employeeSalary(void* pEmployeeA)
{
    return ((Employee*)pEmployeeA)->salary  > 4000;
}

void printEmployee(Employee* p)
{
    printf("Nombre:%s Salario:%.2f\r\n",p->name,p->salary);
}

int printEmployee2(void* p)
{
    int retorno = -1;
    if(p != NULL)
    {
        printf("Nombre:%s Salario:%.2f\r\n",((Employee*)p)->name,((Employee*)p)->salary);
        retorno = 1;
    }
    return retorno;
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}

int aumentarSalarioEn5000(void* pEmployee)
{
    int retorno = -1;
    if(pEmployee != NULL)
    {
        ((Employee*)pEmployee)->salary += 5000;
        retorno = 1;
    }
    return retorno;
}
