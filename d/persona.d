#!/usr/bin/env rdmd

import std.algorithm, std.conv, core.stdc.ctype, std.regex, std.range, std.stdio, std.string;

struct Persona_data {
    uint total_words_spoken;
    uint[string] word_count;
}


void main()
{
    // accumulate inforamation about dramatic personae
    Persona_data[string] info;

    // fill info
    string curpar;
    foreach (line; stdin.byLine()) {
        if (line.startsWith("    ") && line.length > 4 && isalpha(line[4])) {
            // persona is continuing a line
            curpar ~= line[3..$];
        } else if (line.startsWith("  ") && line.length > 2 && isalpha(line[2])) {
            // persona just started speaking
            add_paragraph(curpar, info);
            curpar = to!string(line[2..$]);
        }
    }

    // done, now print collected information
    print_results(info);
}

void add_paragraph(string line, ref Persona_data[string] info)
{
    // figure out persona and sentence
    line = strip(line);
    auto sentence = std.algorithm.find(line, ". ");
    if (sentence.empty)
        return;
    auto persona = line[0..$-sentence.length];
    sentence = toLower(strip(sentence[2..$]));
    // get the words spoken
    auto words = split(sentence, regex("[\t,.;:?!]+"));
    // insert or update information
    if (!(persona in info)) {
        // first time this persone speaketh
        info[persona] = Persona_data();
    }
    info[persona].total_words_spoken += words.length;
    foreach (word; words) {
        ++info[persona].word_count[word];
    }
}

void print_results(Persona_data[string] info)
{
    foreach (persona, data; info) {
        writefln("%20s %6u %6u", persona, data.total_words_spoken, data.word_count.length);
    }
}
