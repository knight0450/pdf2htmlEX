/*
 * Header file for HTMLTextPage
 * Copyright (C) 2013 Lu Wang <coolwanglu@gmail.com>
 */

#ifndef HTMLTEXTPAGE_H__
#define HTMLTEXTPAGE_H__

#include <vector>
#include <memory>
#include <ostream>

#include "Param.h"
#include "StateManager.h"
#include "HTMLTextLine.h"
#include "HTMLState.h"

namespace pdf2htmlEX {

/*
 * Store and optimize a page of text in HTML
 *
 * contains a series of HTMLTextLine
 */

class HTMLTextPage
{
public:
    HTMLTextPage (const Param & param, AllStateManater & all_manager);

    void append_unicodes(const Unicode * u, int l);
    void append_offset(double offset);
    void append_state(const HTMLState & state);

    void dump_text(std::ostream & out);
    void dump_css(std::ostream & out);
    void clear(void);

    void open_new_line(void);

private:
    void optimize(void);

    const Param & param;
    AllStateManater & all_manager;
    HTMLTextLine * last_line;
    std::vector<std::unique_ptr<HTMLTextLine>> text_lines;
};

} //namespace pdf2htmlEX 
#endif //HTMLTEXTPAGE_H__
