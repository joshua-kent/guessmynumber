/* miscellaneous definitions */

#define MISC_H

#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <vector>

using namespace std;

namespace misc {

    class query {
        public:
            int new_query(string, vector<string>, vector<string>,
                             int, int, int, bool, bool);
            string input;
            int input_number;
    };

    int query::new_query(string start, vector<string> opts, vector<string> key,
                         int f_space = 2, int s_space = 1, int t_space = 1,
                         bool tab_opts = true, bool clear = false) {

        /*
        key is what must be typed to get a response, should
        correspond with opts as they have not been merged into a map
        */
        
        string user_input;

        if (clear) { system("cls"); } // clears if clear is true

        cout << start << string(f_space, '\n'); // output start, add specified new lines
        cout << "What do you want to do?" << string(t_space, '\n');

        for (int i = 0; i < opts.size(); i++) {
            if (tab_opts) {
                cout << "    " << opts[i] << endl;
            } else {
                cout << opts[i] << endl;
            }
        }

        cout << string(s_space, '\n') << ": ";
        cin >> user_input;

        for (char &c : user_input) {
            c = tolower(c);
        }

        input = user_input;

        for (int i = 0; i < opts.size(); i++) {
            string current_option = key[i];
            
            for (char &c : current_option) {
                c = tolower(c);
            }
            
            if (user_input == current_option) {
                input_number = i + 1;
            }
        }

        return input_number;
    }
}