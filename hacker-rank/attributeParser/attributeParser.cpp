#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;


struct Tag {
    map<string, string> att;
    map<string, Tag> childs;
};


/**
 * @brief Create a vector with sequential commands
 * 
 * @param command commands in string format
 * @return vector<string> 
 */
vector<string> createCommands(string command) {
    vector<string> subCommands;
    string subStr = "";

    for (int i=1; i<command.size(); i++) {
        if (command[i] != ' ') {
            if (command[i] != '"')
                subStr += command[i];
        } else {
            if (subStr[0] == '=') {
                subStr = "";
            } else {
                subCommands.push_back(subStr);
                subStr = "";
            }
        }
    }
    subCommands.push_back(subStr);

    return subCommands;
}


/**
 * @brief Create a map with all Tags;
 * where key is the tagName and value is the tag;
 * a tag have a map with childs if necessary;
 * 
 * @param N specifies the number of lines in the HRML source program
 * @return map<string, Tag> 
 */
map<string, Tag> createTag(int N) {
    stack<Tag> stk;
    map<string, Tag> tags;

    while (N-- > 0) {
        string command;
        getline(cin, command, '>');
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        Tag tag;
        vector<string> subCommands = createCommands(command);

        if (subCommands[0][0] == '/') {  // close tag
            if (stk.size() == 1) {  // if the tag haven't father
                tags[subCommands[0].substr(1)] = stk.top();
                stk.pop();
            } else {  // if the tag have father
                Tag auxTag = stk.top();
                stk.pop();
                stk.top().childs[subCommands[0].substr(1)] = auxTag;
            }
            continue;
        }

        string tagName = subCommands.front();
        subCommands.erase(subCommands.begin());

        // add the attribute and value to the tag
        while (!subCommands.empty())
        {
            tag.att[subCommands.front()] = subCommands.at(1);
            subCommands.erase(subCommands.begin());
            subCommands.erase(subCommands.begin());
        }

        if (!stk.empty()) // if the tag has a father
        {
            stk.top().childs[tagName];
        }
        stk.push(tag);
        
    }
    
    return tags;
}


/**
 * @brief query a value from a tag attribute;
 * a tag may (have a father) be inside another tag;
 * 
 * example:
 * a.b.c.d~size
 * 'a, b, c, d' are tags, where a is the father of b and so on,
 * and 'size' are a attribute;
 * 
 * @param Q specifies the number of queries
 * @param tags map with all tags
 */
void queryTag(int Q, map<string, Tag> tags) {
    while (Q-- > 0) {
        string commands;
        string command = "";
        Tag tag;
        getline(cin, commands);

        for (int i=0; i<commands.size(); i++) {
            // command tag complete
            if (commands[i] == '.' || commands[i] == '~') {
                if (tag.childs.empty()) {  // tag has a father
                    tag = tags[command];
                } else {  // tag haven't a father
                    Tag tagAux;
                    tagAux = tag.childs[command];
                    tag = tagAux;
                }
                command = "";
            } else {
                command += commands[i];
            }
        }

        if (tag.att[command] == "")  // value not found
            cout << "Not Found!" << endl;
        else  // print the found value
            cout << tag.att[command] << endl;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int N, Q;
    stack<Tag> stk;

    scanf("%d %d\n", &N, &Q);
    
    map<string, Tag> tags = createTag(N);

    queryTag(Q, tags);
    
    return 0;
}
