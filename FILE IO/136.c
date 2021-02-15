/* 136. Convert a Binary Grade File to HTML */
# include <stdio.h>
# include <assert.h>
typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;
int main(void){
    char inputfile[82], outputfile[82];
    scanf("%s %s", &inputfile, &outputfile);
    FILE *ifp = fopen(inputfile, "rb");
    FILE *ofp = fopen(outputfile, "wb");
    assert(ifp != NULL && ofp != NULL);
    Student Eroiko = {"", 0, "", {0}, 0, 0, 0};
    fprintf(ofp, "<table border=\"1\">\n<tbody>\n");
    while (fread(&Eroiko, sizeof(Student), 1, ifp) != 0){
        fprintf(ofp, "<tr>\n<td>%s</td>\n", Eroiko.name);
        fprintf(ofp, "<td>%d</td>\n<td>%s</td>\n", Eroiko.id, Eroiko.phone);
        fprintf(ofp, "<td>%f, %f, %f, %f</td>\n", Eroiko.grade[0], Eroiko.grade[1], Eroiko.grade[2], Eroiko.grade[3]);
        fprintf(ofp, "<td>%d, %d, %d</td>\n</tr>\n", Eroiko.birth_year, Eroiko.birth_month, Eroiko.birth_day);
    }
    fprintf(ofp, "</tbody>\n</table>\n");
    fclose(ifp), fclose(ofp);
    return 0;
}