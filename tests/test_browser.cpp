// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
// Copyright 2005  Braden McDaniel
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

# include <iostream>
# include <fstream>
# include "test_browser.h"

test_browser::test_browser():
    openvrml::browser(std::cout, std::cerr)
{}

std::auto_ptr<openvrml::resource_istream>
test_browser::do_get_resource(const std::string & uri)
{
    using std::auto_ptr;
    using std::invalid_argument;
    using std::string;
    using openvrml::resource_istream;

    class file_resource_istream : public resource_istream {
        std::string url_;
        std::filebuf buf_;

    public:
        explicit file_resource_istream(const std::string & path):
            resource_istream(&this->buf_)
        {
            this->buf_.open(path.c_str(), ios_base::in);
        }

        void url(const std::string & str) throw (std::bad_alloc)
        {
            this->url_ = str;
        }

    private:
        virtual const std::string do_url() const throw ()
        {
            return this->url_;
        }

        virtual const std::string do_type() const throw ()
        {
            return "application/octet-stream";
        }

        virtual bool do_data_available() const throw ()
        {
            return !!(*this);
        }
    };

    const string scheme = uri.substr(0, uri.find_first_of(':'));
    if (scheme != "file") {
        throw invalid_argument('\"' + scheme + "\" URI scheme not supported");
    }
    //
    // file://
    //        ^
    // 01234567
    //
    string path = uri.substr(uri.find_first_of('/', 7));

    auto_ptr<resource_istream> in(new file_resource_istream(path));
    static_cast<file_resource_istream *>(in.get())->url(uri);

    return in;
}
