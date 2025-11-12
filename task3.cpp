#include "header.h"

void saveToFile3(const std::string& filename, const Groups& groups) {
    std::fstream out;
    out.open(filename, std::ios::out | std::ios::trunc);
    for (auto pair: groups) {
        for (auto st: pair.second) {
            out << pair.first << '|' << st.Name << '|'
            << st.Year << '|';
            for (auto dis_grad: st.RecordBook) {
                out << dis_grad.first << ':' << dis_grad.second << ',';
            }
            out << '\n';
        }
    }
    out.close();
}

Score stringToScore(const std::string& str) {
    switch (std::stoi(str)) {
        case 2: return Unsatisfactorily; break;
        case 3: return Satisfactorily; break;
        case 4: return Good; break;
        case 5: return Excellent; break;
    }
}
void loadFromFile3(const std::string& filename, Groups& outGroups) {
    std::fstream in;
    in.open(filename);
    std::string line;
    while (getline(in,line)) {
        std::string buf, groupName, subj;
        int count = 0;
        Student st;
        for (int i=0; i < size(line); i++) {

            if (line[i] != '|') {
                buf += line[i];
            }
            else {                      //считываем до словаря оценок
                if (count == 0) {
                    groupName = buf;
                    buf.clear();
                    count++;
                }
                else if (count == 1) {
                    st.Name = buf;
                    buf.clear();
                    count++;
                }
                else if (count == 2) {
                    st.Year = std::stoi(buf);
                    buf.clear();
                    count = i + 1;
                    break;
                }
            }
        }
        line = line.substr(count);
        for (int i = 0; i < size(line); i++) {  //считываем словарь оценок
            if (line[i] != ':' && line[i] != ',') {
                buf += line[i];
            }
            if (line[i] == ':') {
                subj = buf;
                st.RecordBook[subj] = Good;
                buf.clear();
            }
            if (line[i] == ',') {
                st.RecordBook[subj] = stringToScore(buf);
                buf.clear();
            }
        }
        outGroups[groupName].push_back(st);
    }
}





