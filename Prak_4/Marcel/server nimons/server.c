#include "server.h"

void solution(){
    FILE *req = fopen("request.txt", "r");
    FILE *res = fopen("response.txt", "w");
    if (!req || !res) return;

    char line[256], method[20], path[100], content_type[100] = "N/A", body[600] = "";
    int inBody = 0;

    fgets(line, sizeof(line), req);
    sscanf(line, "%s %s", method, path);

    while (fgets(line, sizeof(line), req)) {
        if (strcmp(line, "\n") == 0 || strcmp(line, "\r\n") == 0) {
            inBody = 1;
            continue;
        }

        if (!inBody) {
            if (strncmp(line, "Content-Type:", 13) == 0) {
                sscanf(line + 13, " %s", content_type);
            }
        } else {
            strcat(body, line);
        }
    }

    fprintf(res, "HTTP/1.1 200 OK\n");
    fprintf(res, "Content-Type: text/plain\n\n");
    fprintf(res, "Method: %s\n", method);
    fprintf(res, "Path: %s\n", path);
    fprintf(res, "Content-Type: %s\n", content_type);
    if (strlen(body) > 0) {
        fprintf(res, "Body: \n%s", body);
    }

    fclose(req);
    fclose(res);
}

// int main(){
//     solution();
//     return 0;
// }