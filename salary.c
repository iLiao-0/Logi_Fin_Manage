#include "employee.h"

// 计算员工工资
void calculate_salary(Employee *emp) {
    switch(emp->type) {
        case TECHNICIAN:  // 技术人员：按工作小时数计薪
            emp->total_salary = emp->salary_data.technician.hours *
                                emp->salary_data.technician.hourly_rate;
            break;

        case SALESPERSON:  // 销售人员：按销售额提成
            emp->total_salary = emp->salary_data.salesperson.sales_amount *
                                emp->salary_data.salesperson.commission_rate;
            break;

        case SECRETARY:  // 文秘：基本工资加奖金
            emp->total_salary = emp->salary_data.secretary.base_salary +
                                emp->salary_data.secretary.bonus;
            break;

        case TECH_MANAGER:  // 技术经理：固定工资加等级奖金
            emp->total_salary = emp->salary_data.tech_manager.fixed_salary +
                                (emp->salary_data.tech_manager.level *
                                 emp->salary_data.tech_manager.level_bonus);
            break;

        case SALES_MANAGER:  // 销售经理：固定工资加销售提成
            emp->total_salary = emp->salary_data.sales_manager.fixed_salary +
                                (emp->salary_data.sales_manager.sales_amount *
                                 emp->salary_data.sales_manager.commission_rate);
            break;
    }
}

// 批量计算总工资
void calculate_all_salaries(Employee *employees, int count) {
    float total_company_salary = 0;
    float type_salaries[5] = {0};  // 每种类型员工的总工资

    for(int i = 0; i < count; i++) {
        calculate_salary(&employees[i]);
        total_company_salary += employees[i].total_salary;
        type_salaries[employees[i].type] += employees[i].total_salary;
    }

    printf("\n=== 工资统计 ===\n");
    printf("公司总工资支出: %.2f\n", total_company_salary);
    printf("\n各类员工工资总额:\n");
    printf("技术人员: %.2f\n", type_salaries[TECHNICIAN]);
    printf("销售人员: %.2f\n", type_salaries[SALESPERSON]);
    printf("文秘: %.2f\n", type_salaries[SECRETARY]);
    printf("技术经理: %.2f\n", type_salaries[TECH_MANAGER]);
    printf("销售经理: %.2f\n", type_salaries[SALES_MANAGER]);
}