#include "server.h"

void solution(){
    FILE *req = fopen("request.txt", "r");
    FILE *res = fopen("response.txt", "w");

    char line[MAX_LINE], method[20], path[100], content_type[100] = "N/A", body[MAX_BODY] = "";
    int inBody = 0;

    fgets(line, sizeof(line), req);
    sscanf(line, "%s %s", method, path);

    while (fgets(line, sizeof(line), req)) {
        if (!inBody) {
            if (strncmp(line, "Content-Type:", 13) == 0) {
                sscanf(line + 13, " %s", content_type);
            }
        }
        else if (strncmp(line, "\r\n", 1) == 0){
            inBody = 1;
            printf("cond\n");
            while(fgets(line, sizeof(line), req)){
                strcat(body, line);
                printf("%s\n", line);
            }
            continue;
        }
        printf("%s", line);
    }
    printf("\nBody: %s\n", body);

    fprintf(res, "HTTP/1.1 200 OK\n");
    fprintf(res, "Content-Type: text/plain\n\n");
    fprintf(res, "Method: %s\n", method);
    fprintf(res, "Path: %s\n", path);
    fprintf(res, "Content-Type: %s\n", content_type);
    if (strlen(body) > 0) {
        fprintf(res, "Body: %s\n", body);
    }

    fclose(req);
    fclose(res);
}

int main(){
    solution();
    return 0;
}