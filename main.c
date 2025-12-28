#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "employee.h"  // 确保这行存在

int main() {
    #ifdef _WIN32
        // 设置控制台输出为UTF-8编码
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif
    SetConsoleOutputCP(65001);
    Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;
    int choice;
    char id[MAX_ID_LEN];
    char filename[100];

    do {
        printf("\n物流财务管理子系统\n");
        printf("1. 添加员工\n");
        printf("2. 显示所有员工\n");
        printf("3. 计算单个员工工资\n");
        printf("4. 保存到文件\n");
        printf("5. 从文件加载\n");
        printf("6. 查找员工\n");
        printf("7. 计算所有员工工资\n");
        printf("8. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(employee_count < MAX_EMPLOYEES) {
                    input_employee_info(&employees[employee_count]);
                    employee_count++;
                } else {
                    printf("员工数量已达上限！\n");
                }
                break;

            case 2:
                for(int i = 0; i < employee_count; i++) {
                    display_employee_info(&employees[i]);
                }
                break;

            case 3:
                printf("请输入员工ID: ");
                scanf("%s", id);
                // 查找员工
                for(int i = 0; i < employee_count; i++) {
                    if(strcmp(employees[i].id, id) == 0) {
                        calculate_salary(&employees[i]);  // 这里调用
                        break;
                    }
                }
                break;

            case 4:
                printf("请输入文件名: ");
                scanf("%s", filename);
                save_to_file(employees, employee_count, filename);
                break;

            case 5:
                printf("请输入文件名: ");
                scanf("%s", filename);
                employee_count = load_from_file(employees, filename);
                break;

            case 6:
                printf("请输入要查找的员工ID: ");
                scanf("%s", id);
                Employee *emp = find_employee_by_id(employees, employee_count, id);
                if(emp != NULL) {
                    display_employee_info(emp);
                } else {
                    printf("未找到该员工！\n");
                }
                break;

            case 7:
                calculate_all_salaries(employees, employee_count);  // 这里调用
                break;

            case 8:
                printf("谢谢使用！\n");
                break;

            default:
                printf("无效选择！\n");
        }
    } while(choice != 8);

    return 0;
}