/*ckwg +29
 * Copyright 2016 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef VITAL_UTIL_TOKEN_EXPAND_EDITOR_H
#define VITAL_UTIL_TOKEN_EXPAND_EDITOR_H


#include <vital/util/string_editor.h>

#include <vital/util/token_expander.h>

namespace kwiver {
namespace vital {

namespace edit_operation {

// ----------------------------------------------------------------
/**
 * @brief String editor that does token/macro expansion.
 *
 */
class VITAL_UTIL_EXPORT token_expand_editor
{
public:
  // -- CONSTRUCTORS --
  token_expand_editor();
  virtual ~token_expand_editor();
  virtual bool process( std::string& line );

  /**
   * @brief Add additional token type expander.
   *
   * Add an additional token expander to the collection. This editor
   * takes ownership of the specified object and will delete it when
   * being destroyed.
   *
   * @param tt New expander object.
   */
  void add_expander( kwiver::vital::token_type * tt );


private:
    token_expander m_token_expander;

}; // end class token_expand_editor

} } } // end namespace

#endif // VITAL_UTIL_TOKEN_EXPAND_EDITOR_H
