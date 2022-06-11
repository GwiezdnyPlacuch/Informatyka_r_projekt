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

        for (auto& c : text) c = toupper(c);

        if (k > 26) k %= 26;
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == ' ') continue;
            text[i] -= k;
        }

        wxString wynik(text.c_str(), wxConvUTF8);

        return wynik;
    }
};

