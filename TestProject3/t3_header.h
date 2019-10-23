struct company {
    char name[20];
    int work_done;
};

struct company_registry {
    struct company companies[50];
    int occupied[50]; /* 0 if the correponding index is not occupied by a company, 1 else*/
};

struct company_registry *ptr;
