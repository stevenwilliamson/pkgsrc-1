$NetBSD: patch-libstdc++-v3_config_os_bsd_dragonfly_ctype__configure__char.cc,v 1.1 2014/09/04 18:43:11 jperkin Exp $

Support DragonFly.

--- libstdc++-v3/config/os/bsd/dragonfly/ctype_configure_char.cc.orig	2014-09-04 10:04:51.024501545 +0000
+++ libstdc++-v3/config/os/bsd/dragonfly/ctype_configure_char.cc
@@ -0,0 +1,99 @@
+// Locale support -*- C++ -*-
+
+// Copyright (C) 2011 Free Software Foundation, Inc.
+//
+// This file is part of the GNU ISO C++ Library.  This library is free
+// software; you can redistribute it and/or modify it under the
+// terms of the GNU General Public License as published by the
+// Free Software Foundation; either version 3, or (at your option)
+// any later version.
+
+// This library is distributed in the hope that it will be useful,
+// but WITHOUT ANY WARRANTY; without even the implied warranty of
+// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+// GNU General Public License for more details.
+
+// Under Section 7 of GPL version 3, you are granted additional
+// permissions described in the GCC Runtime Library Exception, version
+// 3.1, as published by the Free Software Foundation.
+
+// You should have received a copy of the GNU General Public License and
+// a copy of the GCC Runtime Library Exception along with this program;
+// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
+// <http://www.gnu.org/licenses/>.
+
+/** @file ctype_configure_char.cc */
+
+//
+// ISO C++ 14882: 22.1  Locales
+//
+
+#include <locale>
+#include <cstdlib>
+#include <cstring>
+
+namespace std _GLIBCXX_VISIBILITY(default)
+{
+_GLIBCXX_BEGIN_NAMESPACE_VERSION
+
+// Information as gleaned from /usr/include/ctype.h
+  
+  const ctype_base::mask*
+  ctype<char>::classic_table() throw()
+  { return 0; }
+
+  ctype<char>::ctype(__c_locale, const mask* __table, bool __del, 
+		     size_t __refs) 
+  : facet(__refs), _M_del(__table != 0 && __del), 
+  _M_toupper(NULL), _M_tolower(NULL), 
+  _M_table(__table ? __table : classic_table()) 
+  { 
+    memset(_M_widen, 0, sizeof(_M_widen));
+    _M_widen_ok = 0;
+    memset(_M_narrow, 0, sizeof(_M_narrow));
+    _M_narrow_ok = 0;
+  }
+
+  ctype<char>::ctype(const mask* __table, bool __del, size_t __refs) 
+  : facet(__refs), _M_del(__table != 0 && __del), 
+  _M_toupper(NULL), _M_tolower(NULL), 
+  _M_table(__table ? __table : classic_table()) 
+  { 
+    memset(_M_widen, 0, sizeof(_M_widen));
+    _M_widen_ok = 0;
+    memset(_M_narrow, 0, sizeof(_M_narrow));
+    _M_narrow_ok = 0;
+  }
+
+  char
+  ctype<char>::do_toupper(char __c) const
+  { return ::toupper((int) __c); }
+
+  const char*
+  ctype<char>::do_toupper(char* __low, const char* __high) const
+  {
+    while (__low < __high)
+      {
+	*__low = ::toupper((int) *__low);
+	++__low;
+      }
+    return __high;
+  }
+
+  char
+  ctype<char>::do_tolower(char __c) const
+  { return ::tolower((int) __c); }
+
+  const char* 
+  ctype<char>::do_tolower(char* __low, const char* __high) const
+  {
+    while (__low < __high)
+      {
+	*__low = ::tolower((int) *__low);
+	++__low;
+      }
+    return __high;
+  }
+
+_GLIBCXX_END_NAMESPACE_VERSION
+} // namespace
