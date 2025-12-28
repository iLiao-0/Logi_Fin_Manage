#include <stdio.h>
#include <string.h>
#include "employee.h"

// 输入员工信息
void input_employee_info(Employee *emp) {
    printf("输入员工ID: ");
    scanf("%s", emp->id);
    printf("输入员工姓名: ");
    scanf("%s", emp->name);
    printf("输入基本工资: ");
    scanf("%f", &emp->salary);
    printf("输入奖金: ");
    scanf("%f", &emp->bonus);
    printf("输入扣除: ");
    scanf("%f", &emp->deduction);
    emp->net_salary = 0; // 初始化为0，稍后计算
}

// 显示员工信息
void display_employee_info(const Employee *emp) {
    printf("\n员工信息:\n");
    printf("ID: %s\n", emp->id);
    printf("姓名: %s\n", emp->name);
    printf("基本工资: %.2f\n", emp->salary);
    printf("奖金: %.2f\n", emp->bonus);
    printf("扣除: %.2f\n", emp->deduction);
    printf("实发工资: %.2f\n", emp->net_salary);
}

// 计算单个员工工资 - 确保这个函数名完全匹配
void calculate_salary(Employee *emp) {
    emp->net_salary = emp->salary + emp->bonus - emp->deduction;
    printf("员工 %s 的实发工资为: %.2f\n", emp->name, emp->net_salary);
}

// 通过ID查找员工
Employee* find_employee_by_id(Employee *employees, int count, const char *id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(employees[i].id, id) == 0) {
            return &employees[i];
        }
    }
    return NULL;
}

// 计算所有员工工资
void calculate_all_salaries(Employee *employees, int count) {
    float total_salary = 0;
    for (int i = 0; i < count; i++) {
        employees[i].net_salary = employees[i].salary + employees[i].bonus - employees[i].deduction;
        total_salary += employees[i].net_salary;
        printf("员工 %s: %.2f\n", employees[i].name, employees[i].net_salary);
    }
    printf("所有员工总工资: %.2f\n", total_salary);
}

// 保存到文件
void save_to_file(const Employee *employees, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    fprintf(file, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %.2f %.2f %.2f %.2f\n",
                employees[i].id, employees[i].name,
                employees[i].salary, employees[i].bonus,
                employees[i].deduction, employees[i].net_salary);
    }

    fclose(file);
    printf("数据已保存到 %s\n", filename);
}

// 从文件加载
int load_from_file(Employee *employees, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return 0;
    }

    int count;
    fscanf(file, "%d", &count);

    for (int i = 0; i < count && i < MAX_EMPLOYEES; i++) {
        fscanf(file, "%s %s %f %f %f %f",
               employees[i].id, employees[i].name,
               &employees[i].salary, &employees[i].bonus,
               &employees[i].deduction, &employees[i].net_salary);
    }

    fclose(file);
    printf("从 %s 加载了 %d 条记录\n", filename, count);
    return count;
}