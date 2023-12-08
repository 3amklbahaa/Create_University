#include <stdio.h>
#include <string.h>
typedef struct Major{
    char name[30];
    char name_dep[30];
    int nb_students;
    int nb_credits;
    float credit_price;
    char family_name[30];
}Major;
typedef struct university{
    char uni_name[30];
    char addr_uni[30];
    Major major[50];
    int n;
}university;
Major createmajor(){
    Major major;
    printf("plz enter name, dep_name, nb_students, nb_credits, credit_price, family_name: ");
    scanf("%s%s%d%d%f%s",major.name,major.name_dep,&major.nb_students,&major.nb_credits,&major.credit_price,major.family_name);
    return major;
}
university createUni(){
    university Uni;
    printf("plz enter uni_name, addr_uni: ");
    scanf("%s%s",Uni.uni_name,Uni.addr_uni);
    Uni.n=0;
    return Uni;
}
void Add_major(university *uni, Major major){
    if(uni->n<50){
        uni->major[uni->n]=major;
        (uni->n)++;
    }
    else{
        printf("there is no place\n");
    }
}
university Update_Major(char name_major[],university u,float new_cost){
    for(int i=0;i<u.n;i++){
        if(strcmp(name_major,u.major[i].name)==0){
            printf("old cost for %s: %f\n",name_major,u.major[i].credit_price);
            u.major[i].credit_price=new_cost;
            printf("new cost for %s: %f\n",name_major,u.major[i].credit_price);
            return u;
        }
    }
    printf("not found\n");
    return u;
}
void Search_Major(Major major,university u){
    for(int i=0;i<u.n;i++){
        if(strcmp(major.name,u.major[i].name)==0){
            printf("price total pour %s: %f\n",major.name,(u.major[i].credit_price)*(u.major[i].nb_credits));
            return;
        }
    }
    printf("not found\n");
}
int main() {
    int N;
    printf("Enter how many majors you want: ");
    scanf("%d", &N);
    university uni;
    uni = createUni();
    Major major;
    for (int i = 0; i < N; i++) {
        major = createmajor();
        Add_major(&uni, major);
    }
    char name_major[30];
    printf("Enter the name of major to update: ");
    scanf("%s", name_major);
    float new_cost;
    printf("Enter new cost: ");
    scanf("%f", &new_cost);
    uni = Update_Major(name_major, uni, new_cost);
    Search_Major(major, uni);
    return 0;
}
