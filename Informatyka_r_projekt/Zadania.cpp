#include "Zadania.h"

wxString Zadania::encryptV(wxString t, wxString k)
{
    std::string text = t.ToStdString();
    std::string key = k.ToStdString();

    for (auto& c : text) {
        if (std::isdigit(c))
            return "";
    }
    for (auto& c : key) {
        if (std::isdigit(c))
            return "";
    }


    for (auto& c : text) c = toupper(c);
    for (auto& c : key) c = toupper(c);

    std::string out;

    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;

        out += (c + key[j] - 2 * 'A') % 26 + 'A';
        j = (j + 1) % key.length();
    }

    wxString wynik(out.c_str(), wxConvUTF8);

    return wynik;
}

wxString Zadania::decryptV(wxString t, wxString k)
{
    std::string text = t.ToStdString();
    std::string key = k.ToStdString();

    for (auto& c : text) {
        if (std::isdigit(c))
            return "";
    }
    for (auto& c : key) {
        if (std::isdigit(c))
            return "";
    }

    for (auto& c : text) c = toupper(c);
    for (auto& c : key) c = toupper(c);

    std::string out;

    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        char c = text[i];

        if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
        else if (c < 'A' || c > 'Z')
            continue;

        out += (c - key[j] + 26) % 26 + 'A';
        j = (j + 1) % key.length();
    }

    wxString wynik(out.c_str(), wxConvUTF8);

    return wynik;
}

wxString Zadania::encryptC(wxString t, int k) {
    std::string text = t.ToStdString();

    if (k == 0) return t;

    for (auto& c : text) {
        if (std::isdigit(c))
            return "";
    }

    for (auto& c : text) c = toupper(c);

    if (k > 26) k %= 26;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ') continue;
        if (text[i] + k <= 'Z')
            text[i] += k;
        else
            text[i] = text[i] + k - 26;
    }

    wxString wynik(text.c_str(), wxConvUTF8);

    return wynik;
}

wxString Zadania::decryptC(wxString t, int k) {
    std::string text = t.ToStdString();


    if (k == 0) return t;

    for (auto& c : text) {
        if (std::isdigit(c))
            return "";
    }


    for (auto& c : text) c = toupper(c);

    if (k > 26) k %= 26;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ') continue;
        if (text[i] - k >= 'A')
            text[i] -= k;
        else
            text[i] = text[i] + 26 - k;
    }

    wxString wynik(text.c_str(), wxConvUTF8);

    return wynik;
}

bool Zadania::are_anagrams(wxString str1, wxString str2) {

    if (str1.size() != str2.size()) return false;


    std::string s1 = str1.ToStdString();
    std::string s2 = str2.ToStdString();

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i])
            return false;
    }

    return true;
}

bool Zadania::are_palindrome(wxString str1) {

    std::string s1 = str1.ToStdString();
    std::string s2 = s1;

    std::reverse(s2.begin(), s2.end());

    if (s1 != s2) return false;

    return true;

}

int Zadania::ONP(wxString r) {

    std::string wyrazenie = r.ToStdString();
    std::string operatory = "/+-* ";

    if (wyrazenie.length() % 2 == 0) return 0;

    for (auto c : wyrazenie) {
        if (!(std::isdigit(c)) && (operatory.find(c) == std::string::npos))
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
