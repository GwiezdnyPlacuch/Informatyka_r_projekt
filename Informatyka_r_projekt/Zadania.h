#pragma once

#include "wx/wx.h"
#include <string>
#include <stack>

class Zadania
{
public:
    wxString encryptV(wxString t, wxString k);
    wxString decryptV(wxString t, wxString k);

    wxString encryptC(wxString t, int k);
    wxString decryptC(wxString t, int k);

    bool are_anagrams(wxString str1, wxString str2);
    bool are_palindrome(wxString str1);

    int ONP(wxString r) {

        std::string wyrazenie = r.ToStdString();
        std::string operatory = "/+-* ";

        if (wyrazenie.length() % 2==0) return 0;

        for (auto c : wyrazenie) {
            if (!(std::isdigit(c)) && (operatory.find(c)== std::string::npos))
                return 0;
        }

        std::stack<int> stos;
        int n = wyrazenie.length();

        
            for (int i = 0; i < n; i++) {
                int cyfra = (int)wyrazenie.at(i);

                if (isdigit(cyfra)) {
                    cyfra -= 48;
                    stos.push(cyfra);
                }
                else if (isspace(cyfra)) { continue; }
                else {
                    int x, y;
                    if (stos.size() <= 1) return 0;
                    x = stos.top();
                    stos.pop();
                    y = stos.top();
                    stos.pop();
                    
                        
                    switch (wyrazenie.at(i))
                    {
                    case '-':
                        stos.push(y - x);
                        break;
                    case '+':
                        stos.push(y + x);
                        break;
                    case '/':
                        stos.push(y / x);
                        break;
                    case '*':
                        stos.push(y * x);
                        break;
                    }
                }
            }
      
        return stos.top();
        
    }
};

