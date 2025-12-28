#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20
#define MAX_EMPLOYEES 100

typedef struct {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    float salary;
    float bonus;
    float deduction;
    float net_salary;
} Employee;

// 核心函数声明
void input_employee_info(Employee *emp);
void display_employee_info(const Employee *emp);
void calculate_salary(Employee *emp);
void save_to_file(const Employee *employees, int count, const char *filename);
int load_from_file(Employee *employees, const char *filename);
Employee* find_employee_by_id(Employee *employees, int count, const char *id);
void calculate_all_salaries(Employee *employees, int count);

// 辅助函数声明（如果 utils.c 中有这些函数）
void clear_input_buffer();
void display_menu();
int is_valid_number(const char *str);
void format_salary(float salary, char *buffer, int size);

#endif