/*
** Structure declaration for auto dealership sales records.
*/
struct INFO1
{
    char cust_name[21];
    char cust_addr[41];
    char model[21];
    enum
    {
        PURE_CASH,
        CASH_LOAN,
        LEASE
    } type;
    union
    {
        struct
        {
            float msrp;
            float sales_price;
            float sales_tax;
            float licensing_fee;
        } pure_cash;
        struct
        {
            float msrp;
            float sales_price;
            float sales_tax;
            float licensing_fee;
            float down_payment;
            int loan_duration;
            float interest_rate;
            f float monthly_payment;
            char bank[21];
        } cash_loan;
        struct
        {
            float msrp;
            float sales_price;
            float down_payment;
            float security_deposit;
            float monthly_payment;
            float lease_term;
        } lease;
    } info;
};

/*
** Improved structure declaration for auto dealership sales records.
*/
struct INFO2
{
    char cust_name[21];
    char cust_addr[41];
    char model[21];
    float msrp;
    float sales_price;
    enum
    {
        PURE_CASH,
        CASH_LOAN,
        LEASE
    } type;
    union
    {
        struct
        {
            float sales_tax;
            float licensing_fee;
        } pure_cash;
        struct
        {
            float sales_tax;
            float licensing_fee;
            float down_payment;
            int loan_duration;
            float interest_rate;
            float monthly_payment;
            char bank[21];
        } cash_loan;
        struct
        {
            float down_payment;
            float security_deposit;
            float monthly_payment;
            float lease_term;
        } lease;
    } info;
};