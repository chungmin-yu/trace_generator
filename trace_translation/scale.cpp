#include <bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[]){
    
    FILE    *traceFile;
    char     lineBuffer[1024];
    uint64_t timestamp, memory_addr;
    int region_num, tmp, rw;

   if (argc >= 2) {
        char tracefilename[100] = "./";
        strcat(tracefilename, argv[1]);
        traceFile = fopen(tracefilename, "rt");
        cout << "open the trace file: " << tracefilename << endl;
    } else {
        cout << "error!" << endl;
        return 0;
    }
    fseek(traceFile, 0, SEEK_SET);


    std::ofstream ofs;
    ofs.open("output.trace");

    while(!feof(traceFile)) {
        if (fgets(lineBuffer, 1024, traceFile) == NULL) break;

        sscanf(lineBuffer,"%lu %d %lu %d %d", &timestamp, &region_num, &memory_addr, &tmp, &rw);
        timestamp = (uint64_t) (timestamp * 0.42);
        ofs << timestamp << " " << region_num << " " << memory_addr << " " << tmp << " " << rw << endl;

    }

    fclose(traceFile);
    ofs.close();
    return 0;
}