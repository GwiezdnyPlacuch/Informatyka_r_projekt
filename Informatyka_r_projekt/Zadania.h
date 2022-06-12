#pragma once

#include "wx/wx.h"

class Zadania
{
    //todo
    //upewnic sie ze nie da sie wpisac glupot
public:
    wxString encryptV(wxString t, wxString k)
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

    wxString decryptV(wxString t, wxString k)
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

        wxString wynik(out.c_str(),wxConvUTF8);

        return wynik;
    }

    wxString encryptC(wxString t, int k) {
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

    wxString decryptC(wxString t, int k) {
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

    bool are_anagrams(wxString str1, wxString str2) {
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
};

