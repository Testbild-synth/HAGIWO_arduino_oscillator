#pragma once

// THE FOLLOWING LINES OF CODE FOLLOWS THE MIT LICENSE
//
// MIT License
//
// Copyright (c) 2019 Strick Yak
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// These are from : https://raw.githubusercontent.com/schollz/nyblcore/main/bytebeat/bytebeat.ino
// poetasters are below.


// <bb>
// {"description": "frequency dancer", "author": "ANON256-64", "url":
// "https://www.reddit.com/r/bytebeat/comments/11krrl8/frequency_dancer/",
// "date": "2023-03-07", "codeOriginal": "(t%125&t>>8)|t>>4|t*t>>8&t>>8",
// "codeMinified": "t%125&t>>8|t>>4|t*t>>8&t>>8"}
/*
  byte bb0_vals[] = {125, 8, 4, 8, 8};
  byte bb0_set(byte a, byte b) { bb0_vals[a * 5 / 255] = b * 249 / 255; }
  byte bb0() {
  return (t % bb0_vals[0] & t >> bb0_vals[1]) | t >> bb0_vals[2] |
         t * t >> bb0_vals[3] & t >> bb0_vals[4];
  }*/

// {"author": "ryg", "children": [{"description": "triangle waves", "url":
// "http://www.pouet.net/topic.php?which=8357&page=11#c389010", "date":
// "2011-10-05", "codeOriginal": "(t<<5)^-(t>>3&1)"}, {"description": "the
// general form is (t<&lt;N)^-(t<<(N-8)&1)", "codeOriginal":
// "(t<<4)^-(t>>4&1)"}, {"codeOriginal": "(t<<3)^-(t>>5&1)"}, {"description": "a
// jaunty tune", "url":
// "http://www.pouet.net/topic.php?which=8357&page=17#c389829", "date":
// "2011-10-10", "codeOriginal":
// "(t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48)>>(((t>>16)|(t>>17))&1)",
// "codeMinified":
// "t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48>>((t>>16|t>>17)&1)"}]}
/*
  byte bb1_vals[] = {4, 4, 1};
  byte bb1_set(byte a, byte b) { bb1_vals[a * 3 / 255] = b * 7 / 255; }
  byte bb1() { return (t << bb1_vals[0]) ^ -(t >> bb1_vals[bb1_vals[2]] & 1); }
*/
// {"author": "viznut", "children": [{"url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-09-18",
// "codeOriginal": "t*(((t>>12)|(t>>8))&(63&(t>>4)))", "codeMinified":
// "t*((t>>12|t>>8)&63&t>>4)"}, {"description": "Sin() isn't kosher, people!",
// "url": "https://www.pouet.net/topic.php?which=8357&page=4#c388477", "date":
// "2011-09-30", "codeOriginal": "(t>>6|t|t>>(t>>16))*10+((t>>11)&7)",
// "codeMinified": "10*(t>>6|t|t>>(t>>16))+(7&t>>11)", "starred": 1},
// {"description": "Combined xpansive's and varjohukka's stuff", "url":
// "https://www.pouet.net/topic.php?which=8357&page=4#c388488", "date":
// "2011-09-30", "codeOriginal": "(t>>7|t|t>>6)*10+4*(t&t>>13|t>>6)", "starred":
// 2}, {"description": "Another attempt at melody construction (\"Running
// man\")", "url": "http://www.pouet.net/topic.php?which=8357&page=9#c388930",
// "date": "2011-10-04", "codeOriginal":
// "(t*((3+(1^t>>10&5))*(5+(3&t>>14))))>>(t>>8&3)", "codeMinified":
// "t*(3+(1^t>>10&5))*(5+(3&t>>14))>>(t>>8&3)", "starred": 2}, {"description":
// "#countercomplex \"moon scanner generalization\", based on jaffa's formula",
// "url": "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date":
// "2011-10-06", "codeOriginal": "((t>>5&t)-(t>>5)+(t>>5&t))+(t*((t>>14)&14))",
// "codeMinified": "2*(t>>5&t)-(t>>5)+t*(t>>14&14)", "starred": 1}]}
/*
  byte bb2_vals[] = {7, 6, 10, 4, 13, 6};
  byte bb2_set(byte a, byte b) { bb2_vals[a * 6 / 255] = b * 25 / 255; }
  byte bb2() {
  return (t >> bb2_vals[0] | t | t >> bb2_vals[1]) * bb2_vals[2] +
         bb2_vals[3] * (t & t >> bb2_vals[4] | t >> bb2_vals[5]);
  }
*/
// {"author": "GDPlayer_1035", "children": [{"description": "test3", "url":
// "https://www.reddit.com/r/bytebeat/comments/q6ar3c/test3/", "date":
// "2021-10-12", "sampleRate": 44100, "codeOriginal":
// "((t*t-t/400*t/800^t/900)&192&-t/30)+t/40&t/80^t/80"}, {"description":
// "thing", "url": "https://www.reddit.com/r/bytebeat/comments/q8cqdv/thing/",
// "date": "2021-10-15", "sampleRate": 44100, "codeOriginal":
// "(t&t/2&t/4)*t/4E3", "starred": 1}]}
/*
  byte bb3_vals[] = {2, 4};
  byte bb3_set(byte a, byte b) { bb3_vals[a * 2 / 255] = b * 7 / 255; }
  byte bb3() { return (t & t / bb3_vals[0] & t / bb3_vals[1]) * t / 4E3; }
*/
// {"author": "Unknown", "url":
// "https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/", "date":
// "2014-03-16", "children": [{"description": "Wip", "codeOriginal":
// "(((t&t*5)|t>>4)+(t|t>>4*t<<8-1))^t>>12", "codeMinified":
// "(t&5*t|t>>4)+(t|t>>4*t<<7)^t>>12"}, {"description": "Extremely loud grinding
// machine", "codeOriginal": "t/(t%(t>>8|t>>16))", "starred": 1},
// {"description": "Everything is broken", "codeOriginal":
// "(t*t/(1+(t>>9&t>>8)))&128", "codeMinified": "t*t/(1+(t>>9&t>>8))&128",
// "starred": 1}, {"description": "It wont stop", "codeOriginal":
// "t*((t/401)^(t/400))", "codeMinified": "t*(t/401^t/400)"}, {"description":
// "Ststututterter", "codeOriginal": "(t*(-(t>>8|t|t>>9|t>>13)))^t",
// "codeMinified": "t*-(t>>8|t|t>>9|t>>13)^t"}, {"description": "Waiver",
// "codeOriginal": "(((t/91)&t)^((t/90)&t))-1", "codeMinified":
// "(t/91&t^t/90&t)-1"}, {"description": "Glissando", "codeOriginal":
// "(t*t)/(t>>13 ^ t>>8)", "codeMinified": "t*t/(t>>13^t>>8)"}, {"description":
// "Plucker v2", "codeOriginal": "((t/4)>>t/4)|(t>>2)", "codeMinified":
// "t/4>>t/4|t>>2"}]}
/*
  byte bb4_vals[] = {8, 9, 13};
  byte bb4_set(byte a, byte b) { bb4_vals[a * 3 / 255] = b * 25 / 255; }
  byte bb4() {
  return (t * (-(t >> bb4_vals[0] | t | t >> bb4_vals[1] | t >> bb4_vals[2]))) ^
         t;
  }
*/
// {"author": "xpansive", "children": [{"description": "Lost in Space", "url":
// "http://www.pouet.net/topic.php?which=8357&page=3#c388375", "date":
// "2011-09-29", "codeOriginal": "((t*(t>>8|t>>9)&46&t>>8)) ^ (t&t>>13|t>>6)",
// "codeMinified": "t*(t>>8|t>>9)&46&t>>8^(t&t>>13|t>>6)"}, {"url":
// "http://www.pouet.net/topic.php?which=8357&page=21#c401775", "date":
// "2012-02-25", "codeOriginal": "t%(t/(t>>9|t>>13))"}]}
/*
  byte bb5_vals[] = {8, 9, 46, 8, 13, 6};
  byte bb5_set(byte a, byte b) { bb5_vals[a * 6 / 255] = b * 91 / 255; }
  byte bb5() {
  return ((t * (t >> bb5_vals[0] | t >> bb5_vals[1]) & bb5_vals[2] &
           t >> bb5_vals[3])) ^
         (t & t >> bb5_vals[4] | t >> bb5_vals[5]);
  }
*/
// {"author": "SArpnt", "children": [{"description": "pwm serpinski harmony",
// "url":
// "https://www.reddit.com/r/bytebeat/comments/g9106h/pwm_serpinski_harmony/",
// "date": "2020-04-27", "codeOriginal": "t&(t>>7)-t&t>>8"}, {"description":
// "rhythmic thing", "url":
// "https://www.reddit.com/r/bytebeat/comments/govfve/rhythmic_thing/", "date":
// "2020-05-23", "codeOriginal": "t*2>>(t*4.5>>4)"}, {"description": "buzzy
// grindy beat", "url":
// "https://www.reddit.com/r/bytebeat/comments/imprs9/buzzy_grindy_beat/",
// "date": "2020-09-04", "codeOriginal":
// "t/((t>>3-(t>>14)%2)%(26>>(t>>16)%3))%1024/12<<9/((t>>5)%128)",
// "codeMinified": "t/((t>>3-(t>>14)%2)%(26>>(t>>16)%3))%1024/12<<9/(t>>5&127)",
// "starred": 1}, {"description": "i don't have a name for this", "url":
// "https://www.reddit.com/r/bytebeat/comments/ns22lb/i_dont_have_a_name_for_this/",
// "date": "2021-06-04", "codeOriginal": "(t*3&t>>6)%76"}]}
byte bb6_vals[] = {3, 6, 76};
byte bb6_set(byte a, byte b) {
  bb6_vals[a * 3 / 255] = b * 151 / 255;
}
byte bb6() {
  return (t * bb6_vals[0] & t >> bb6_vals[1]) % bb6_vals[2];
}
// {"author": "ryg", "children": [{"description": "triangle waves", "url":
// "http://www.pouet.net/topic.php?which=8357&page=11#c389010", "date":
// "2011-10-05", "codeOriginal": "(t<<5)^-(t>>3&1)"}, {"description": "the
// general form is (t<&lt;N)^-(t<<(N-8)&1)", "codeOriginal":
// "(t<<4)^-(t>>4&1)"}, {"codeOriginal": "(t<<3)^-(t>>5&1)"}, {"description": "a
// jaunty tune", "url":
// "http://www.pouet.net/topic.php?which=8357&page=17#c389829", "date":
// "2011-10-10", "codeOriginal":
// "(t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48)>>(((t>>16)|(t>>17))&1)",
// "codeMinified":
// "t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48>>((t>>16|t>>17)&1)"}]}
/*
  byte bb7_vals[] = {12, 64, 1, 10, 11, 48, 16, 17, 1};
  byte bb7_set(byte a, byte b) { bb7_vals[a * 9 / 255] = b * 127 / 255; }
  byte bb7() {
  return (t * (t >> bb7_vals[0]) * bb7_vals[bb7_vals[2]] +
          (t >> bb7_vals[8]) * (t >> bb7_vals[3]) * (t >> bb7_vals[4]) *
              bb7_vals[5]) >>
         (((t >> bb7_vals[6]) | (t >> bb7_vals[7])) & 1);
  }
*/
// {"author": "tangent128", "url":
// "http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html?showComment=1317761042403#c4044676811126652266",
// "date": "2011-10-04", "codeOriginal": "t * ( ((t>>9)&10) | ((t>>11)&24)
// ^((t>>10)&15&(t>>15)) )", "codeMinified":
// "t*(t>>9&10|t>>11&24^t>>10&15&t>>15)"}
byte bb8_vals[] = {9, 10, 11, 24, 10, 15, 15};
byte bb8_set(byte a, byte b) {
  bb8_vals[a * 7 / 255] = b * 47 / 255;
}
byte bb8() {
  return t * (((t >> bb8_vals[0]) & bb8_vals[1]) |
              ((t >> bb8_vals[2]) & bb8_vals[3]) ^
              ((t >> bb8_vals[4]) & bb8_vals[5] & (t >> bb8_vals[6])));
}
// {"author": "wiretapped", "url": "https://www.noisebridge.net/wiki/Bytebeat",
// "children": [{"date": "2012-02-23", "codeOriginal":
// "t^t>>4^(t*((t>>(11+(t>>16)%3))%16))^t*3", "codeMinified":
// "t^t>>4^(t>>11+(t>>16)%3)%16*t^3*t"}, {"date": "2012-07-07", "codeOriginal":
// "t*(3+(t>>10)%(4+(t>>11)%8))|(t>>5)", "codeMinified":
// "t*(3+(t>>10)%(4+(t>>11)%8))|t>>5"}, {"date": "2014-07-11", "codeOriginal":
// "t*(1+((t>>10)*(43+(2*(t>>(15-((t>>16)%13)))%8)))%8)*(1+(t>>14)%4)",
// "codeMinified": "t*(1+(t>>10)*(43+2*(t>>15-(t>>16)%13)%8)%8)*(1+(t>>14)%4)",
// "starred": 1}, {"date": "2015-03-20", "codeOriginal":
// "(1+(t>>10)%7)*((t*(1+(t>>13)%4))%(24+(t>>14)*9%8)&16)*10", "codeMinified":
// "(1+(t>>10)%7)*(t*(1+(t>>13)%4)%(24+9*(t>>14)%8)&16)*10"}, {"date":
// "2015-03-20", "codeOriginal":
// "((t*(1|(t>>10-((t>>17)%4))%8))&(8<<((t>>13)%4))*((1|(t>>15)%8)))
// *11*(t>>10)", "codeMinified":
// "11*(t*(1|(t>>10-(t>>17)%4)%8)&(8<<(t>>13)%4)*(1|(t>>15)%8))*(t>>10)"},
// {"date": "2017-09-30", "codeOriginal":
// "(((t>>((t>>12)%4))+t*(1+(1+(t>>16)%6)*((t>>10))*(t>>11)%8))^(t>>13))^((t>>6))",
// "codeMinified":
// "(t>>(t>>12)%4)+t*(1+(1+(t>>16)%6)*(t>>10)*(t>>11)%8)^t>>13^t>>6"}]}
/*
  byte bb9_vals[] = {4, 11, 16, 3, 16, 3};
  byte bb9_set(byte a, byte b) { bb9_vals[a * 6 / 255] = b * 31 / 255; }
  byte bb9() {
  return t ^ t >> bb9_vals[0] ^
         (t *
          ((t >> (bb9_vals[1] + (t >> bb9_vals[2]) % bb9_vals[bb9_vals[5]])) %
           bb9_vals[4])) ^
         t * 3;
  }*/

// {"author": "ryg", "children": [{"description": "triangle waves", "url":
// "http://www.pouet.net/topic.php?which=8357&page=11#c389010", "date":
// "2011-10-05", "codeOriginal": "(t<<5)^-(t>>3&1)"}, {"description": "the
// general form is (t<&lt;N)^-(t<<(N-8)&1)", "codeOriginal":
// "(t<<4)^-(t>>4&1)"}, {"codeOriginal": "(t<<3)^-(t>>5&1)"}, {"description": "a
// jaunty tune", "url":
// "http://www.pouet.net/topic.php?which=8357&page=17#c389829", "date":
// "2011-10-10", "codeOriginal":
// "(t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48)>>(((t>>16)|(t>>17))&1)",
// "codeMinified":
// "t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48>>((t>>16|t>>17)&1)"}]}
/*
  byte bb10_vals[] = {5, 3, 1};
  byte bb10_set(byte a, byte b) { bb10_vals[a * 3 / 255] = b * 9 / 255; }
  byte bb10() {
  return (t << bb10_vals[0]) ^ -(t >> bb10_vals[bb10_vals[2]] & 1);
  }
*/
// {"description": "Sierpinski harmony", "children": [{"author": "miiro", "url":
// "https://youtu.be/qlrs2Vorw2Y?t=2m14s", "date": "2011-09-30", "codeOriginal":
// "t*5&(t>>7)|t*3&(t*4>>10)", "codeMinified": "5*t&t>>7|3*t&4*t>>10",
// "starred": 2}, {"description": "remix of miiro's 1-line symphony", "author":
// "stephth", "url": "https://news.ycombinator.com/item?id=3063359#3064986",
// "date": "2011-10-03", "codeOriginal":
// "t*9&(t*1>>4)|t*5&(t>>7)|t*3&(t*4>>12)", "codeMinified":
// "9*t&t>>4|5*t&t>>7|3*t&t>>10", "starred": 1}, {"description": "Long
// Sierpinski Harmony", "author": "viznut", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-10-10",
// "codeOriginal": "(t*5&t>>7)|(t*3&t>>10)", "codeMinified":
// "5*t&t>>7|3*t&t>>10"}, {"description": "percussive", "author": "radavis",
// "url": "https://github.com/radavis/bytebeat/blob/master/errie_error.c",
// "date": "2014-08-10", "codeOriginal":
// "(((t*9)&(t>>4))|(t*5&t>>7)|(t*3&t/1024))-1", "codeMinified":
// "(9*t&t>>4|5*t&t>>7|3*t&t>>10)-1"}, {"description": "magical", "author":
// "radavis", "url":
// "https://github.com/radavis/bytebeat/blob/master/errie_error.c", "date":
// "2014-08-10", "codeOriginal": "((t*9)&(t>>4))|(t*5&t>>7)|(t*3&t/1024)-1",
// "codeMinified": "9*t&t>>4|5*t&t>>7|(3*t&t>>10)-1"}, {"description": "BM9
// harmony", "author": "May_I_Change_My_Name", "url":
// "https://www.reddit.com/r/bytebeat/comments/yi1cf9/u_wot_m9/", "date":
// "2022-10-31", "codeOriginal": "2*t&(t>>8)|5*t&(t>>7)|9*t&(t>>4)|15*t&(t>>4)",
// "codeMinified": "2*t&t>>8|5*t&t>>7|9*t&t>>4|15*t&t>>4"}, {"description":
// "minimal sierpinski harmony", "author": "viznut", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "codeOriginal":
// "t&t>>8"}]}
/*
  byte bb11_vals[] = {2, 8, 5, 7, 9, 4, 15, 4};
  byte bb11_set(byte a, byte b) { bb11_vals[a * 8 / 255] = b * 29 / 255; }
  byte bb11() {
  return bb11_vals[0] * t & (t >> bb11_vals[1]) |
         bb11_vals[2] * t & (t >> bb11_vals[3]) |
         bb11_vals[bb11_vals[5]] * t & (t >> bb11_vals[7]) |
         bb11_vals[6] * t & (t >> 4);
  }
*/
// {"description": "chaotic craziness", "author": "T_yknow", "url":
// "https://www.reddit.com/r/bytebeat/comments/120dijk/chaotic_craziness/",
// "date": "2023-03-24", "sampleRate": 22050, "codeOriginal": "(t^t>>12)*t>>8",
// "starred": 1}
/*
  byte bb12_vals[] = {12, 8};
  byte bb12_set(byte a, byte b) { bb12_vals[a * 2 / 255] = b * 23 / 255; }
  byte bb12() { return (t ^ t >> bb12_vals[0]) * t >> bb12_vals[1]; }
  // {"description": "Explosions", "codeOriginal": "t>>5|(t>>2)*(t>>5)",
  // "starred": 1}
  byte bb13_vals[] = {5, 2, 5};
  byte bb13_set(byte a, byte b) { bb13_vals[a * 3 / 255] = b * 9 / 255; }
  byte bb13() {
  return t >> bb13_vals[0] | (t >> bb13_vals[1]) * (t >> bb13_vals[2]);
  }
*/
// {"description": "Modem melody", "children": [{"author": "krcko", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-10-04",
// "codeOriginal": "(t&t>>12)*(t>>4|t>>8)", "starred": 1}, {"description": "The
// 8-bit echo", "author": "Unknown", "url":
// "https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/", "date":
// "2014-03-16", "codeOriginal": "(t-(t>>4&t>>8)&t>>12)-1"}, {"description":
// "19-character dubstep", "author": "SthephanShi", "url":
// "https://dollchan.net/btb/res/55.html#359", "date": "2023-01-18",
// "sampleRate": 44100, "codeOriginal": "t&t>>12|t/(t&t>>12)"}]}
/*
  byte bb14_vals[] = {12, 12};
  byte bb14_set(byte a, byte b) { bb14_vals[a * 2 / 255] = b * 23 / 255; }
  byte bb14() { return t & t >> bb14_vals[0] | t / (t & t >> bb14_vals[1]); }
*/
// {"author": "Unknown", "url":
// "https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/", "date":
// "2014-03-16", "children": [{"description": "Wip", "codeOriginal":
// "(((t&t*5)|t>>4)+(t|t>>4*t<<8-1))^t>>12", "codeMinified":
// "(t&5*t|t>>4)+(t|t>>4*t<<7)^t>>12"}, {"description": "Extremely loud grinding
// machine", "codeOriginal": "t/(t%(t>>8|t>>16))", "starred": 1},
// {"description": "Everything is broken", "codeOriginal":
// "(t*t/(1+(t>>9&t>>8)))&128", "codeMinified": "t*t/(1+(t>>9&t>>8))&128",
// "starred": 1}, {"description": "It wont stop", "codeOriginal":
// "t*((t/401)^(t/400))", "codeMinified": "t*(t/401^t/400)"}, {"description":
// "Ststututterter", "codeOriginal": "(t*(-(t>>8|t|t>>9|t>>13)))^t",
// "codeMinified": "t*-(t>>8|t|t>>9|t>>13)^t"}, {"description": "Waiver",
// "codeOriginal": "(((t/91)&t)^((t/90)&t))-1", "codeMinified":
// "(t/91&t^t/90&t)-1"}, {"description": "Glissando", "codeOriginal":
// "(t*t)/(t>>13 ^ t>>8)", "codeMinified": "t*t/(t>>13^t>>8)"}, {"description":
// "Plucker v2", "codeOriginal": "((t/4)>>t/4)|(t>>2)", "codeMinified":
// "t/4>>t/4|t>>2"}]}
/*
  byte bb15_vals[] = {4, 4, 2};
  byte bb15_set(byte a, byte b) { bb15_vals[a * 3 / 255] = b * 7 / 255; }
  byte bb15() {
  return ((t / bb15_vals[0]) >> t / bb15_vals[1]) | (t >> bb15_vals[2]);
  }
*/
// {"author": "Niklas_Roy", "url":
// "http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html?showComment=1318497618021#c332012386255047591",
// "date": "2011-10-13", "children": [{"description": "Arcade game",
// "codeOriginal": "( t* (( t>>9| t>>13 ) & 15)) & 129", "codeMinified":
// "t*((t>>9|t>>13)&15)&129"}, {"description": "Clean melody", "codeOriginal":
// "t*(t>>9|t>>13)&16"}, {"description": "Louder clean melody", "codeOriginal":
// "9*(t*((t>>9|t>>13)&15)&16)"}]}
/*
  byte bb16_vals[] = {9, 9, 13, 15, 16};
  byte bb16_set(byte a, byte b) { bb16_vals[a * 5 / 255] = b * 31 / 255; }
  byte bb16() {
  return bb16_vals[0] *
         (t * ((t >> bb16_vals[1] | t >> bb16_vals[2]) & bb16_vals[3]) &
          bb16_vals[4]);
  }
*/
// {"author": "Chasyxx", "children": [{"description": "Electrohouse2",
// "remixed": {"description": "Electrohouse", "author": "Anonymous from russian
// imageboards", "url": "http://arhivach.ng/thread/28592/"}, "url":
// "https://www.reddit.com/r/bytebeat/comments/qi3enp/with_new_bytecodes_already_posted_here_are_all/",
// "date": "2021-10-29", "codeOriginal":
// "t>>t%(t%2?t&32768?41:t&16384?51:61:34)&(t/9&t/7|t/5&t/3|t|t*3&t*5|t*7&t*9)>>4"},
// {"description": "Modem melody II", "url":
// "https://www.reddit.com/r/bytebeat/comments/10bh30y/modem_melody_ii/",
// "date": "2023-01-14", "sampleRate": 32000, "codeOriginal":
// "(((((t&t>>12)*(t>>4|t>>8))&255) +
// (((t>>12)-1)&1?((t^(t>>t))^(t^(t>>t))+((t>>15)+1)):0)))/2", "codeMinified":
// "(((t&t>>12)*(t>>4|t>>8)&255)+((t>>12)-1&1?t^t>>t^(t^t>>t)+((t>>15)+1):0))/2",
// "starred": 1}, {"description": "WARP_TUNNEL", "url":
// "https://www.reddit.com/r/bytebeat/comments/10iv4dc/warp_tunnel/", "date":
// "2023-01-22", "codeOriginal":
// "((t*2)+2)^(t*(1<<(((t>>8)^(t>>8)+(t>>16))+1)%7))", "codeMinified":
// "2*t+2^t*(1<<((t>>8^(t>>8)+(t>>16))+1)%7)"}]}
byte bb17_vals[] = {2, 2, 1, 8, 8, 16, 1, 7};
byte bb17_set(byte a, byte b) {
  bb17_vals[a * 8 / 255] = b * 31 / 255;
}
byte bb17() {
  return ((t * bb17_vals[0]) + bb17_vals[bb17_vals[2]]) ^
         (t * (bb17_vals[6] << (((t >> bb17_vals[3]) ^
                                 (t >> bb17_vals[4]) + (t >> bb17_vals[5])) +
                                1) %
               bb17_vals[7]));
}
// {"description": "Sierpinski harmony", "children": [{"author": "miiro", "url":
// "https://youtu.be/qlrs2Vorw2Y?t=2m14s", "date": "2011-09-30", "codeOriginal":
// "t*5&(t>>7)|t*3&(t*4>>10)", "codeMinified": "5*t&t>>7|3*t&4*t>>10",
// "starred": 2}, {"description": "remix of miiro's 1-line symphony", "author":
// "stephth", "url": "https://news.ycombinator.com/item?id=3063359#3064986",
// "date": "2011-10-03", "codeOriginal":
// "t*9&(t*1>>4)|t*5&(t>>7)|t*3&(t*4>>12)", "codeMinified":
// "9*t&t>>4|5*t&t>>7|3*t&t>>10", "starred": 1}, {"description": "Long
// Sierpinski Harmony", "author": "viznut", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-10-10",
// "codeOriginal": "(t*5&t>>7)|(t*3&t>>10)", "codeMinified":
// "5*t&t>>7|3*t&t>>10"}, {"description": "percussive", "author": "radavis",
// "url": "https://github.com/radavis/bytebeat/blob/master/errie_error.c",
// "date": "2014-08-10", "codeOriginal":
// "(((t*9)&(t>>4))|(t*5&t>>7)|(t*3&t/1024))-1", "codeMinified":
// "(9*t&t>>4|5*t&t>>7|3*t&t>>10)-1"}, {"description": "magical", "author":
// "radavis", "url":
// "https://github.com/radavis/bytebeat/blob/master/errie_error.c", "date":
// "2014-08-10", "codeOriginal": "((t*9)&(t>>4))|(t*5&t>>7)|(t*3&t/1024)-1",
// "codeMinified": "9*t&t>>4|5*t&t>>7|(3*t&t>>10)-1"}, {"description": "BM9
// harmony", "author": "May_I_Change_My_Name", "url":
// "https://www.reddit.com/r/bytebeat/comments/yi1cf9/u_wot_m9/", "date":
// "2022-10-31", "codeOriginal": "2*t&(t>>8)|5*t&(t>>7)|9*t&(t>>4)|15*t&(t>>4)",
// "codeMinified": "2*t&t>>8|5*t&t>>7|9*t&t>>4|15*t&t>>4"}, {"description":
// "minimal sierpinski harmony", "author": "viznut", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "codeOriginal":
// "t&t>>8"}]}
byte bb18_vals[] = {5, 7, 3, 4, 10};
byte bb18_set(byte a, byte b) {
  bb18_vals[a * 5 / 255] = b * 19 / 255;
}
byte bb18() {
  return t * bb18_vals[0] & (t >> bb18_vals[1]) |
         t * bb18_vals[2] & (t * bb18_vals[3] >> bb18_vals[4]);
}
// {"description": "Modem melody", "children": [{"author": "krcko", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-10-04",
// "codeOriginal": "(t&t>>12)*(t>>4|t>>8)", "starred": 1}, {"description": "The
// 8-bit echo", "author": "Unknown", "url":
// "https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/", "date":
// "2014-03-16", "codeOriginal": "(t-(t>>4&t>>8)&t>>12)-1"}, {"description":
// "19-character dubstep", "author": "SthephanShi", "url":
// "https://dollchan.net/btb/res/55.html#359", "date": "2023-01-18",
// "sampleRate": 44100, "codeOriginal": "t&t>>12|t/(t&t>>12)"}]}
byte bb19_vals[] = {12, 4, 8};
byte bb19_set(byte a, byte b) {
  bb19_vals[a * 3 / 255] = b * 23 / 255;
}
byte bb19() {
  return (t & t >> bb19_vals[0]) * (t >> bb19_vals[1] | t >> bb19_vals[2]);
}
// {"author": "harism", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-10-09",
// "codeOriginal": "((t>>1%128)+20)*3*t>>14*t>>18", "codeMinified":
// "3*((t>>1)+20)*t>>14*t>>18"}
byte bb20_vals[] = {1, 128, 20, 3, 14, 18};
byte bb20_set(byte a, byte b) {
  bb20_vals[a * 6 / 255] = b * 255 / 255;
}
byte bb20() {
  return ((t >> bb20_vals[0] % bb20_vals[1]) + bb20_vals[2]) * bb20_vals[3] *
         t >>
         bb20_vals[4] * t >> bb20_vals[5];
}
// {"description": "Wheezing modem", "children": [{"codeOriginal":
// "100*((t<<2|t>>5|t^63)&(t<<10|t>>11))"}, {"author": "Devan Wolf", "url":
// "https://dollchan.net/btb/res/3.html#224", "date": "2022-10-18",
// "codeOriginal": "(t<<1&t*3&-t>>5&t>>10)-1"}]}
byte bb21_vals[] = {100, 2, 5, 63, 10, 11};
byte bb21_set(byte a, byte b) {
  bb21_vals[a * 6 / 255] = b * 199 / 255;
}
byte bb21() {
  return bb21_vals[0] *
         ((t << bb21_vals[1] | t >> bb21_vals[2] | t ^ bb21_vals[3]) &
          (t << bb21_vals[4] | t >> bb21_vals[5]));
}
// {"author": "tejeez", "children": [{"url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-09-18",
// "codeOriginal": "(t*(t>>5|t>>8))>>(t>>16)", "codeMinified":
// "t*(t>>5|t>>8)>>(t>>16)"}, {"url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-09-18",
// "codeOriginal": "t*(((t>>11)&(t>>8))&(123&(t>>3)))", "codeMinified":
// "t*(t>>11&t>>8&123&t>>3)"}, {"description": "Noisy beats", "url":
// "https://youtu.be/GtQdIYUtAHg?t=2m55s", "date": "2011-09-18", "codeOriginal":
// "((-t&4095)*(255&t*(t&(t>>13)))>>12)+(127&t*(234&t>>8&t>>3)>>(3&t>>14))",
// "codeMinified":
// "((-t&4095)*(255&t*(t&t>>13))>>12)+(127&t*(234&t>>8&t>>3)>>(3&t>>14))"},
// {"description": "Bassline #countercomplex", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-10-05",
// "codeOriginal": "(~t>>2)*((127&t*(7&t>>10))<(245&t*(2+(5&t>>14))))",
// "starred": 1}]}
byte bb22_vals[] = {11, 8, 123, 3};
byte bb22_set(byte a, byte b) {
  bb22_vals[a * 4 / 255] = b * 245 / 255;
}
byte bb22() {
  return t * (((t >> bb22_vals[0]) & (t >> bb22_vals[1])) &
              (bb22_vals[2] & (t >> bb22_vals[3])));
}
// {"author": "Devan Wolf", "url": "https://dollchan.net/btb/res/3.html#224",
// "date": "2022-10-18", "children": [{"description": "Stand, Back, You...",
// "codeOriginal": "(t>>(t>>(t>>12&15)))>>t", "codeMinified":
// "t>>(t>>(t>>12&15))>>t"}, {"description": "Some kind of Non-JS echo effect I
// discovered?", "codeOriginal": "((t*(t>>12))<<(-t>>10&7))&-t>>2",
// "codeMinified": "t*(t>>12)<<(-t>>10&7)&-t>>2"}, {"description": "Nice
// stepdown effects there", "codeOriginal": "t*(t>>(t>>10&7)&t>>12)"},
// {"description": "Cool percussion track", "codeOriginal":
// "-t*(t>>3|t>>4|t>>5|t>>6|t>>7)-t"}, {"description": "Inchwormy Beat",
// "codeOriginal": "t<<(t>>8)*231", "starred": 1}, {"description": "Tunnel
// sounds music?", "codeOriginal": "(43*(t|t>>11)&255)*(8|~t>>6&55)>>6",
// "starred": 1}, {"description": "Combination stimmer + Street Surfer",
// "remixed": {"author": "stimmer", "url":
// "https://forum.arduino.cc/t/one-line-algorithmic-music/73409"},
// "codeOriginal":
// "(t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))",
// "starred": 1}]}
byte bb23_vals[] = {10, 7, 12};
byte bb23_set(byte a, byte b) {
  bb23_vals[a * 3 / 255] = b * 23 / 255;
}
byte bb23() {
  return t * (t >> (t >> bb23_vals[0] & bb23_vals[1]) & t >> bb23_vals[2]);
}
// {"author": "lhphr", "url": "https://dollchan.net/btb/res/44.html#44", "date":
// "2022-04-14", "children": [{"description": "idk it's \"t%\"", "codeOriginal":
// "(t%(t&t>>12))*t>>8", "codeMinified": "t%(t&t>>12)*t>>8"}, {"description":
// ":arp", "date": "2022-03-13", "sampleRate": 44100, "codeOriginal":
// "((t>>(1+(t>>18)%2))%256*(t%(4+((t>>15)%8))))", "codeMinified":
// "(t>>1+(t>>18)%2)%256*(t%(4+(t>>15)%8))"}, {"description": "%ral", "date":
// "2022-04-14", "sampleRate": 22050, "codeOriginal":
// "t>>6^t&t>>9^t>>12|(t<<(t>>6)%4^-t&-t>>13)%128^-t>>1"}, {"description":
// "Fractalized Past", "url": "https://dollchan.net/btb/res/44.html#69", "date":
// "2022-05-26", "codeOriginal":
// "(t>>10^t>>11)%5*((t>>14&3^t>>15&1)+1)*t%99+((3+(t>>14&3)-(t>>16&1))/3*t%99&64)",
// "starred": 2}]}
/*
  byte bb24_vals[] = {6, 9, 12, 6, 4, 13, 128, 1};
  byte bb24_set(byte a, byte b) { bb24_vals[a * 8 / 255] = b * 255 / 255; }
  byte bb24() {
  return t >> bb24_vals[0] ^ t & t >> bb24_vals[bb24_vals[7]] ^
             t >> bb24_vals[2] |
         (t << (t >> bb24_vals[3]) % bb24_vals[4] ^ -t & -t >> bb24_vals[5]) %
                 bb24_vals[6] ^
             -t >> 1;
  }
*/
// {"author": "SArpnt", "children": [{"description": "pwm serpinski harmony",
// "url":
// "https://www.reddit.com/r/bytebeat/comments/g9106h/pwm_serpinski_harmony/",
// "date": "2020-04-27", "codeOriginal": "t&(t>>7)-t&t>>8"}, {"description":
// "rhythmic thing", "url":
// "https://www.reddit.com/r/bytebeat/comments/govfve/rhythmic_thing/", "date":
// "2020-05-23", "codeOriginal": "t*2>>(t*4.5>>4)"}, {"description": "buzzy
// grindy beat", "url":
// "https://www.reddit.com/r/bytebeat/comments/imprs9/buzzy_grindy_beat/",
// "date": "2020-09-04", "codeOriginal":
// "t/((t>>3-(t>>14)%2)%(26>>(t>>16)%3))%1024/12<<9/((t>>5)%128)",
// "codeMinified": "t/((t>>3-(t>>14)%2)%(26>>(t>>16)%3))%1024/12<<9/(t>>5&127)",
// "starred": 1}, {"description": "i don't have a name for this", "url":
// "https://www.reddit.com/r/bytebeat/comments/ns22lb/i_dont_have_a_name_for_this/",
// "date": "2021-06-04", "codeOriginal": "(t*3&t>>6)%76"}]}
/*
  byte bb25_vals[] = {7, 8};
  byte bb25_set(byte a, byte b) { bb25_vals[a * 2 / 255] = b * 15 / 255; }
  byte bb25() { return t & (t >> bb25_vals[0]) - t & t >> bb25_vals[1]; }
*/
// {"author": "Unknown", "url":
// "https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/", "date":
// "2014-03-16", "children": [{"description": "Wip", "codeOriginal":
// "(((t&t*5)|t>>4)+(t|t>>4*t<<8-1))^t>>12", "codeMinified":
// "(t&5*t|t>>4)+(t|t>>4*t<<7)^t>>12"}, {"description": "Extremely loud grinding
// machine", "codeOriginal": "t/(t%(t>>8|t>>16))", "starred": 1},
// {"description": "Everything is broken", "codeOriginal":
// "(t*t/(1+(t>>9&t>>8)))&128", "codeMinified": "t*t/(1+(t>>9&t>>8))&128",
// "starred": 1}, {"description": "It wont stop", "codeOriginal":
// "t*((t/401)^(t/400))", "codeMinified": "t*(t/401^t/400)"}, {"description":
// "Ststututterter", "codeOriginal": "(t*(-(t>>8|t|t>>9|t>>13)))^t",
// "codeMinified": "t*-(t>>8|t|t>>9|t>>13)^t"}, {"description": "Waiver",
// "codeOriginal": "(((t/91)&t)^((t/90)&t))-1", "codeMinified":
// "(t/91&t^t/90&t)-1"}, {"description": "Glissando", "codeOriginal":
// "(t*t)/(t>>13 ^ t>>8)", "codeMinified": "t*t/(t>>13^t>>8)"}, {"description":
// "Plucker v2", "codeOriginal": "((t/4)>>t/4)|(t>>2)", "codeMinified":
// "t/4>>t/4|t>>2"}]}
byte bb26_vals[] = {13, 8};
byte bb26_set(byte a, byte b) {
  bb26_vals[a * 2 / 255] = b * 25 / 255;
}
byte bb26() {
  return (t * t) / (t >> bb26_vals[0] ^ t >> bb26_vals[1]);
}
// {"description": "Duck Hunt", "remixed": {"description": "Noise Maker",
// "author": "Gabriel Miceli", "url":
// "https://www.youtube.com/watch?v=V4GfkFbDojc"}, "author": "Diicorp95", "url":
// "https://www.reddit.com/r/bytebeat/comments/s4oi7c/11025_hz_duck_hunt/",
// "date": "2022-01-15", "sampleRate": 11025, "codeOriginal":
// "((t>>9^(t>>9)-1^1)%13*t&31)*(2+(t>>4))", "starred": 1}
/*
  byte bb27_vals[] = {9, 9, 1, 1, 13, 31, 2, 4};
  byte bb27_set(byte a, byte b) { bb27_vals[a * 8 / 255] = b * 61 / 255; }
  byte bb27() {
  return ((t >> bb27_vals[0] ^
           (t >> bb27_vals[bb27_vals[bb27_vals[6]]]) - bb27_vals[3] ^ 1) %
              bb27_vals[bb27_vals[7]] * t &
          bb27_vals[5]) *
         (2 + (t >> 4));
  }
*/
// {"author": "visy", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "date": "2011-09-18",
// "codeOriginal": "t*(t>>8*((t>>15)|(t>>8))&(20|(t>>19)*5>>t|(t>>3)))",
// "codeMinified": "t*(t>>8*(t>>15|t>>8)&(20|5*(t>>19)>>t|t>>3))"}

byte bb28_vals[] = {8, 15, 8, 20, 19, 5, 3};
byte bb28_set(byte a, byte b) {
  bb28_vals[a * 7 / 255] = b * 39 / 255;
}
byte bb28() {
  return t * (t >> bb28_vals[0] * ((t >> bb28_vals[1]) | (t >> bb28_vals[2])) &
              (bb28_vals[bb28_vals[6]] |
               (t >> bb28_vals[4]) * bb28_vals[5] >> t | (t >> 3)));
}

// {"author": "Unknown", "url":
// "https://www.reddit.com/r/bytebeat/comments/20km9l/cool_equations/", "date":
// "2014-03-16", "children": [{"description": "Wip", "codeOriginal":
// "(((t&t*5)|t>>4)+(t|t>>4*t<<8-1))^t>>12", "codeMinified":
// "(t&5*t|t>>4)+(t|t>>4*t<<7)^t>>12"}, {"description": "Extremely loud grinding
// machine", "codeOriginal": "t/(t%(t>>8|t>>16))", "starred": 1},
// {"description": "Everything is broken", "codeOriginal":
// "(t*t/(1+(t>>9&t>>8)))&128", "codeMinified": "t*t/(1+(t>>9&t>>8))&128",
// "starred": 1}, {"description": "It wont stop", "codeOriginal":
// "t*((t/401)^(t/400))", "codeMinified": "t*(t/401^t/400)"}, {"description":
// "Ststututterter", "codeOriginal": "(t*(-(t>>8|t|t>>9|t>>13)))^t",
// "codeMinified": "t*-(t>>8|t|t>>9|t>>13)^t"}, {"description": "Waiver",
// "codeOriginal": "(((t/91)&t)^((t/90)&t))-1", "codeMinified":
// "(t/91&t^t/90&t)-1"}, {"description": "Glissando", "codeOriginal":
// "(t*t)/(t>>13 ^ t>>8)", "codeMinified": "t*t/(t>>13^t>>8)"}, {"description":
// "Plucker v2", "codeOriginal": "((t/4)>>t/4)|(t>>2)", "codeMinified":
// "t/4>>t/4|t>>2"}]}
/*
  byte bb29_vals[] = {1, 9, 8, 128};
  byte bb29_set(byte a, byte b) { bb29_vals[a * 4 / 255] = b * 255 / 255; }
  byte bb29() {
  return (t * t / (bb29_vals[0] + (t >> bb29_vals[1] & t >> bb29_vals[2]))) &
         bb29_vals[3];
  }
*/
// {"author": "Devan Wolf", "url": "https://dollchan.net/btb/res/3.html#224",
// "date": "2022-10-18", "children": [{"description": "Stand, Back, You...",
// "codeOriginal": "(t>>(t>>(t>>12&15)))>>t", "codeMinified":
// "t>>(t>>(t>>12&15))>>t"}, {"description": "Some kind of Non-JS echo effect I
// discovered?", "codeOriginal": "((t*(t>>12))<<(-t>>10&7))&-t>>2",
// "codeMinified": "t*(t>>12)<<(-t>>10&7)&-t>>2"}, {"description": "Nice
// stepdown effects there", "codeOriginal": "t*(t>>(t>>10&7)&t>>12)"},
// {"description": "Cool percussion track", "codeOriginal":
// "-t*(t>>3|t>>4|t>>5|t>>6|t>>7)-t"}, {"description": "Inchwormy Beat",
// "codeOriginal": "t<<(t>>8)*231", "starred": 1}, {"description": "Tunnel
// sounds music?", "codeOriginal": "(43*(t|t>>11)&255)*(8|~t>>6&55)>>6",
// "starred": 1}, {"description": "Combination stimmer + Street Surfer",
// "remixed": {"author": "stimmer", "url":
// "https://forum.arduino.cc/t/one-line-algorithmic-music/73409"},
// "codeOriginal":
// "(t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))",
// "starred": 1}]}
/*
  byte bb30_vals[] = {12, 10, 7, 2};
  byte bb30_set(byte a, byte b) { bb30_vals[a * 4 / 255] = b * 23 / 255; }
  byte bb30() {
  return ((t * (t >> bb30_vals[0]))
          << (-t >> bb30_vals[1] & bb30_vals[bb30_vals[3]])) &
         -t >> 2;
  }
*/
// {"author": "Devan Wolf", "url": "https://dollchan.net/btb/res/3.html#224",
// "date": "2022-10-18", "children": [{"description": "Stand, Back, You...",
// "codeOriginal": "(t>>(t>>(t>>12&15)))>>t", "codeMinified":
// "t>>(t>>(t>>12&15))>>t"}, {"description": "Some kind of Non-JS echo effect I
// discovered?", "codeOriginal": "((t*(t>>12))<<(-t>>10&7))&-t>>2",
// "codeMinified": "t*(t>>12)<<(-t>>10&7)&-t>>2"}, {"description": "Nice
// stepdown effects there", "codeOriginal": "t*(t>>(t>>10&7)&t>>12)"},
// {"description": "Cool percussion track", "codeOriginal":
// "-t*(t>>3|t>>4|t>>5|t>>6|t>>7)-t"}, {"description": "Inchwormy Beat",
// "codeOriginal": "t<<(t>>8)*231", "starred": 1}, {"description": "Tunnel
// sounds music?", "codeOriginal": "(43*(t|t>>11)&255)*(8|~t>>6&55)>>6",
// "starred": 1}, {"description": "Combination stimmer + Street Surfer",
// "remixed": {"author": "stimmer", "url":
// "https://forum.arduino.cc/t/one-line-algorithmic-music/73409"},
// "codeOriginal":
// "(t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))",
// "starred": 1}]}
byte bb31_vals[] = {12, 15};
byte bb31_set(byte a, byte b) {
  bb31_vals[a * 2 / 255] = b * 29 / 255;
}
byte bb31() {
  return (t >> (t >> (t >> bb31_vals[0] & bb31_vals[1]))) >> t;
}
// {"description": "One-liner", "author": "\u00b5B", "url":
// "https://chipmusic.org/%C2%B5b/music/one-liner/", "date": "2011-10-02",
// "codeOriginal":
// "(64*(t>>3|t>>4|t>>9)+(t>>11&t<<2))^2*(t>>16|t|t>>7)+32*(t>>t&32)",
// "codeMinified":
// "64*(t>>3|t>>4|t>>9)+(t>>11&t<<2)^2*(t>>16|t|t>>7)+32*(t>>t&32)"}
byte bb32_vals[] = {64, 3, 4, 9, 11, 2, 2, 16, 7, 32, 32};
byte bb32_set(byte a, byte b) {
  bb32_vals[a * 11 / 255] = b * 127 / 255;
}
byte bb32() {
  return (bb32_vals[0] * (t >> bb32_vals[1] | t >> bb32_vals[bb32_vals[5]] |
                          t >> bb32_vals[3]) +
          (t >> bb32_vals[4] & t << bb32_vals[6])) ^
         2 * (t >> bb32_vals[bb32_vals[8]] | t | t >> 7) +
         bb32_vals[9] * (t >> t & bb32_vals[10]);
}
// {"description": "2ch.so Generative Music and remixes vol.1", "author":
// "Anonymous from russian imageboards", "url":
// "http://abload.de/img/1405110021643uguil.jpg", "date": "2014-07-11",
// "children": [{"description": "1) THE SWINGS", "codeOriginal":
// "(t%262144<131072)?(((t/64)>>3&t*2&t*10)|(t>>5&t*6)&(t>>4|t>>5)):(t%262144>131072&t%262144<163840)?(t>>4&t*8)&(t>>5|t>>4)|(t*3&t*10):(t%262144>163840&t%262144<196608)?(t>>4&t*8)&(t>>5|t>>4)|(t*3&t*6):(t%262144>196608&t%262144<229376)?(t>>4&t*8)&(t>>5|t>>4)|(t*4&t*6):(t%262144>229376&t%262144<245760)?(t>>4&t*8)&(t>>5|t>>4)|(t*4&t*2):(t>>4&t*8)&(t>>4)|(t*4&t*2)>>20",
// "codeMinified":
// "131072>t%262144?t/64>>3&2*t&10*t|t>>5&6*t&(t>>4|t>>5)d31072<t%262144&163840>t%262144?t>>4&8*t&(t>>5|t>>4)|3*t&10*t:163840<t%262144&196608>t%262144?t>>4&8*t&(t>>5|t>>4)|3*t&6*t:196608<t%262144&229376>t%262144?t>>4&8*t&(t>>5|t>>4)|4*t&6*t:229376<t%262144&245760>t%262144?t>>4&8*t&(t>>5|t>>4)|4*t&2*t:t>>4&8*t&t>>4|(4*t&2*t)>>20",
// "starred": 2}, {"description": "2) ZEMFIRA", "url":
// "http://arhivach.ng/thread/28592/#71681967", "codeOriginal":
// "((t*40>>430|t*40>>4)*430)", "codeMinified": "430*(5*t>>11|5*t>>1)",
// "starred": 1}, {"description": "4) CAT-GIRL", "codeOriginal":
// "t<35000?((t*8)|(t>>2)+(t*13)|(t>>3)%t|t>>5):(t<67500?((t*9)|(t>>2)+(t*13)|(t>>3)%t|t>>5):(t<84000?((t*9)|(t>>2)+(t*12)|(t>>3)%t|t>>5):(t<98000?((t*8)|(t>>2)+(t*12)|(t>>3)%t|t>>5):(t<129000?((t*8)|(t>>2)+(t*13)|(t>>3)%t|t>>5):t%0))))",
// "codeMinified":
// "129E3>t?(35E3>t?8:84E3>t?9:8)*t|(t>>2)+(67500>t?13:98E3>t?12:13)*t|t>>3|t>>5:0",
// "starred": 2}, {"description": "7) RICK ROLL", "codeOriginal":
// "t>125000?t*4.238:t>124375?t*0.01:t>125000?t*4.238:t>122500?t*4.757:t>120000?t*3.364:t>118750?t*0.01:t>115000?t*3.364:t>113750?t*3.564:t>110000?t*4:t>108750?t*0.01:t>106250?t*4.757:t>105000?t*0.01:t>102500?t*4.238:t>101250?t*3.564:t>100000?t*4.238:t>98750?t*3.564:t>97500?t*3.175:t>95000?t*3.564:t>93750?t*4:t>91250?t*4.238:t>90000?t*0.01:t>87500?t*4.757:t>86250?t*0.01:t>83750?t*4.757:t>82500?t*3.564:t>81250?t*4.238:t>80000?t*3.564:t>78750?t*3.175:t>77500?t*0.01:t>72500?t*4.757:t>71250?t*0.01:t>68750?t*5.339:t>67500?t*0.01:t>65000?t*5.339:t>63750?t*3.564:t>62500?t*4.238:t>61250?t*3.564:t>60000?t*3.175:t>52500?t*3.175:t>45000?t*4.757:t>36250?t*4.283:t>35000?t*5.339:t>33750?t*5.657:t>32500?t*6.35:t>25000?t*5.656:t>20000?t*5.04:t>18500?t*3.36:t>7500?t*5.04:t*4.236",
// "codeMinified":
// "125E3<t?4.238*t:124375<t?.01*t:125E3<t?4.238*t:122500<t?4.757*t:12E4<t?3.364*t:118750<t?.01*t:115E3<t?3.364*t:113750<t?3.564*t:11E4<t?4*t:108750<t?.01*t:106250<t?4.757*t:105E3<t?.01*t:102500<t?4.238*t:101250<t?3.564*t:1E5<t?4.238*t:98750<t?3.564*t:97500<t?3.175*t:95E3<t?3.564*t:93750<t?4*t:91250<t?4.238*t:9E4<t?.01*t:87500<t?4.757*t:86250<t?.01*t:83750<t?4.757*t:82500<t?3.564*t:81250<t?4.238*t:8E4<t?3.564*t:78750<t?3.175*t:77500<t?.01*t:72500<t?4.757*t:71250<t?.01*t:68750<t?5.339*t:67500<t?.01*t:65E3<t?5.339*t:63750<t?3.564*t:62500<t?4.238*t:61250<t?3.564*t:6E4<t?3.175*t:52500<t?3.175*t:45E3<t?4.757*t:36250<t?4.283*t:35E3<t?5.339*t:33750<t?5.657*t:32500<t?6.35*t:25E3<t?5.656*t:2E4<t?5.04*t:18500<t?3.36*t:7500<t?5.04*t:4.236*t",
// "starred": 1}, {"description": "9) SADLY", "url":
// "http://arhivach.ng/thread/28592/#71681889", "codeOriginal":
// "((t*4>>43|t*4>>4)*43)", "codeMinified": "43*(t>>41|t>>2)"}, {"description":
// "11) THE HIT OF THE SEASON", "url":
// "http://arhivach.ng/thread/28592/#71678428", "codeOriginal":
// "(t>0&t<65535?t%32>(t/10000)?t>>4:t>>6:0+t>65535&t<65535*2?t%32>(t%43)?t>>4:t>>6:0+t>65535*2&t<65535*3?t%36>(t%43)?t>>4:t>>6:0+t>65535*3&t<65535*4?t%64>(t%43)?t>>4:t>>6:0+t>65535*4&t<65535*5?t%43>5?t<<3:t>>6:0+t>65535*5&t<65535*6?t%27>5?t<<3:t>>6:0+t>65535*6&t<65535*8?t%63>5?t<<3:t>>6:0)&(t>>4)",
// "codeMinified":
// "(0<t&65535>t?t%32>t/1E4?t>>4:t>>6:65535<0+t&131070>t?t%32>t%43?t>>4:t>>6:131070<0+t&196605>t?t%36>t%43?t>>4:t>>6:196605<0+t&262140>t?t%64>t%43?t>>4:t>>6:262140<0+t&327675>t?5<t%43?t<<3:t>>6:327675<0+t&393210>t?5<t%27?t<<3:t>>6:393210<0+t&524280>t?5<t%63?t<<3:t>>6:0)&t>>4",
// "starred": 1}, {"description": "12) PSYCHEDELIC", "codeOriginal":
// "t<40000?((t<20000?((t%(t>>9)*10)|(t/2)&t):(t*(t>>9)*10)&t/2)|(t%(t>>9)*3)&t/16):(t*(t>>9)^t)",
// "codeMinified":
// "4E4>t?(2E4>t?t%(t>>9)*10|t/2&t:t*(t>>9)*10&t/2)|t%(t>>9)*3&t/16:t*(t>>9)^t"},
// {"description": "15) FRACTAL", "codeOriginal":
// "((t*2>>43|t*3*5>>4)*19)&(t*7>>172)/2", "codeMinified":
// "19*(2*t>>43|15*t>>4)&(7*t>>172)/2"}]}
byte bb33_vals[] = {4, 43, 4, 4, 43};
byte bb33_set(byte a, byte b) {
  bb33_vals[a * 5 / 255] = b * 85 / 255;
}
byte bb33() {
  return (
           (t * bb33_vals[0] >> bb33_vals[1] | t * bb33_vals[2] >> bb33_vals[3]) *
           bb33_vals[4]);
}
// {"author": "Devan Wolf", "url": "https://dollchan.net/btb/res/3.html#224",
// "date": "2022-10-18", "children": [{"description": "Stand, Back, You...",
// "codeOriginal": "(t>>(t>>(t>>12&15)))>>t", "codeMinified":
// "t>>(t>>(t>>12&15))>>t"}, {"description": "Some kind of Non-JS echo effect I
// discovered?", "codeOriginal": "((t*(t>>12))<<(-t>>10&7))&-t>>2",
// "codeMinified": "t*(t>>12)<<(-t>>10&7)&-t>>2"}, {"description": "Nice
// stepdown effects there", "codeOriginal": "t*(t>>(t>>10&7)&t>>12)"},
// {"description": "Cool percussion track", "codeOriginal":
// "-t*(t>>3|t>>4|t>>5|t>>6|t>>7)-t"}, {"description": "Inchwormy Beat",
// "codeOriginal": "t<<(t>>8)*231", "starred": 1}, {"description": "Tunnel
// sounds music?", "codeOriginal": "(43*(t|t>>11)&255)*(8|~t>>6&55)>>6",
// "starred": 1}, {"description": "Combination stimmer + Street Surfer",
// "remixed": {"author": "stimmer", "url":
// "https://forum.arduino.cc/t/one-line-algorithmic-music/73409"},
// "codeOriginal":
// "(t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))",
// "starred": 1}]}
byte bb34_vals[] = {3, 4, 5, 6, 7};
byte bb34_set(byte a, byte b) {
  bb34_vals[a * 5 / 255] = b * 13 / 255;
}
byte bb34() {
  return -t * (t >> bb34_vals[0] | t >> bb34_vals[1] | t >> bb34_vals[2] |
               t >> bb34_vals[3] | t >> bb34_vals[4]) -
         t;
}
// {"description": "I have made a thing#2", "author": "Anonymous", "url":
// "https://dollchan.net/btb/res/3.html#78", "date": "2022-06-19",
// "codeOriginal": "(t>>10|t*5)&(t>>8|t*4)&(t>>4|t*6)"}
byte bb35_vals[] = {10, 5, 8, 4, 4, 6};
byte bb35_set(byte a, byte b) {
  bb35_vals[a * 6 / 255] = b * 19 / 255;
}
byte bb35() {
  return (t >> bb35_vals[0] | t * bb35_vals[1]) &
         (t >> bb35_vals[2] | t * bb35_vals[3]) &
         (t >> bb35_vals[4] | t * bb35_vals[5]);
}
// {"author": "k0370_", "url": "https://dollchan.net/btb/res/3.html#258",
// "children": [{"description": "\u2014", "date": "2022-10-10", "codeOriginal":
// "((t*t>>9|t*(t>>16))|t>>4)", "codeMinified": "t*t>>9|t*(t>>16)|t>>4"},
// {"description": "beat thing", "date": "2022-10-26", "codeOriginal":
// "((t*6&t>>5|127*t>>4)>>t/64&t>>5|t>>4|t>>t/64)", "codeMinified":
// "(6*t&t>>5|127*t>>4)>>t/64&t>>5|t>>4|t>>t/64"}, {"description": "high rhythm
// thing", "date": "2022-11-22", "sampleRate": 32000, "codeOriginal":
// "(t>>(t>>13)*t/127)|t>>4", "codeMinified": "t>>(t>>13)*t/127|t>>4"},
// {"description": "first made it", "date": "2022-11-22", "codeOriginal":
// "t+(t&1)+(t>>5)*(t>>1)/1|t>>4|t>>8", "codeMinified":
// "t+(t&1)+(t>>5)*(t>>1)|t>>4|t>>8"}]}
byte bb36_vals[] = {6, 5, 127, 4, 64, 5, 4, 64};
byte bb36_set(byte a, byte b) {
  bb36_vals[a * 8 / 255] = b * 253 / 255;
}
byte bb36() {
  return ((t * bb36_vals[0] & t >> bb36_vals[1] |
           bb36_vals[2] * t >> bb36_vals[3]) >>
          t / bb36_vals[bb36_vals[6]] &
          t >> bb36_vals[5] |
          t >> 4 | t >> t / bb36_vals[7]);
}
// {"author": "bear @ celephais", "url":
// "http://viznut.fi/demos/unix/bytebeat_formulas.txt", "codeOriginal":
// "t+(t&t^t>>6)-t*((t>>9)&(t%16?2:6)&t>>9)", "codeMinified":
// "t+(t&t^t>>6)-t*(t>>9&(t%16?2:6)&t>>9)"}
byte bb37_vals[] = {6, 9, 16, 2, 6, 9};
byte bb37_set(byte a, byte b) {
  bb37_vals[a * 6 / 255] = b * 31 / 255;
}
byte bb37() {
  return t + (t & t ^ t >> bb37_vals[0]) -
         t * ((t >> bb37_vals[1]) &
              (t % bb37_vals[bb37_vals[3]] ? 2 : bb37_vals[4]) &
              t >> bb37_vals[5]);
}
// {"descriotion": "Feel the funk y'all (or something)", "author": "George",
// "url":
// "http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html?showComment=1318282586154#c3276288453210259061",
// "date": "2011-10-10", "codeOriginal": "20 * t*t* (t >>11)/7", "codeMinified":
// "20*t*t*(t>>11)/7", "starred": 1}
byte bb38_vals[] = {20, 11, 7};
byte bb38_set(byte a, byte b) {
  bb38_vals[a * 3 / 255] = b * 39 / 255;
}
byte bb38() {
  return bb38_vals[0] * t * t * (t >> bb38_vals[1]) / bb38_vals[2];
}
// {"author": "godinpants", "url":
// "https://chipmusic.org/forums/post/79378/#p79378", "date": "2011-10-01",
// "codeOriginal": "t / 3 >> (t % 40 + 5) | t / (24 + t & 3) >> (t % (15 - ((t
// >> 15) % 8) * 6) + 5)", "codeMinified":
// "t/3>>t%40+5|t/(24+t&3)>>t%(15-(t>>15)%8*6)+5"}
byte bb39_vals[] = {3, 40, 5, 24, 3, 15, 15, 8, 6, 5};
byte bb39_set(byte a, byte b) {
  bb39_vals[a * 10 / 255] = b * 79 / 255;
}
byte bb39() {
  return t / bb39_vals[0] >> (t % bb39_vals[1] + bb39_vals[2]) |
         t / (bb39_vals[bb39_vals[4]] + t & 3) >>
         (t % (bb39_vals[bb39_vals[9]] -
               ((t >> bb39_vals[bb39_vals[8]]) % bb39_vals[7]) * 6) +
          5);
}
void rythmical(int pb1) {

  switch (pb1) {
    case 1:  // poetaster the next three together
      //setLimits(1,8,1,8,1,8); // aMin, aMax, etc
      setLimits(1, 32, 1, 16, 1, 9); // aMin, aMax, etc
      //result = ( ~t >>7? ~t>>3:~t>>5) * ( (127 & t * ( b & t >> 9) ) < (254 & t * ( 2 + ( c & t >> a ) ) ) );
      result = t >> c ^ t & 1 | t + (t ^ t >> 13) - t * ( (t >> 5 ? b : a) & t >> ( 8 - ( a >> 1 )  ) );  // ( t%8 ? ~t >> 9 & b: ~t >>11 & c )
      break;
    case 2:
      setLimits(1, 16, 1, 16, 1, 16);
      result =  t >> 4 ^ t & c | t + (t ^ t >> 8) - t * ((t >> 3 ? b : a) & t >> ( 5 - ( b >> 1 )  ) );
      // ^ t << 1 & (a & 12 ? t >> 4 : t >> 10)
      break;
    case 3:
      setLimits(1, 16, 1, 16, 1, 16);
      result = t >> (2 * a) ^ t & c | t + (t ^ t >> 21) - t * ((t % 8 ? b : a) & t >> ( 8 - ( b >> 5 )  ) );
      break;

    case 4: //  poetaster
      pb1 = 5; // skip
      setLimits(0, 16, 0, 16, 0, 16);
      //if (t > 65536) t = -65536;
      result = ((t % 32 ? ~t >> 2 : t >> 3) & t + (t >> a) + ( ~ (t ^ b / 2 | t >> c) )  );

      //result=  ((t%4 ? c : b) & ((t<<1)^-(t>>a&1) &  ( 127 << (t+ b) | (t >> c)));
      break;

    case 5:  // always sirens noisy based on https://www.pouet.net/topic.php?post=388938
      setLimits(1, 16, 1, 16, 1, 16); // aMin, aMax, etc
      result =  (t >> 3 & a) + (t * ( 0xC4 + a >> ( t >> 3 % b) & (13 + c) ) | t >> c ) + (int)cos( t * 0xC4 + b);
    //      techno result = t ^ ( t >> c) - t | t >> a * t<<1 & (t&3 ? t >> b: t >> 13 ) ^ ( (t >> 3 ? 8 : 3 ) & t >> 128);

    case 6:   // poetaster the devil. pulses and mana, mana.three controls can cross conflict or harmonize nice. turn c up first
      setLimits(1, 30, 1, 15, 1, 30);
      result = t *  t << 1 & (t & 7 ? t >> 3 : t >> c) ^ ((t >> 7 ? 2 : b) & t >> (c + a)) | t + ((t ^ t >> 13)) | a * t >> b ^ t & c ;
      break;
    case 7:  // poetaster, noisy bassline , arps with tight snare  ... evolves. needs work?
      setLimits(1, 16, 1, 41, 1, 30);
      result = t * ((t >> 7 ? a : c ) & t >> a ) ^ t << 1 & (t & 7 ? t >> 5 : t >> c) - b * t >> 3 ^ t & (42 - b) ;
      break;
    case 8: // started with vizmut paper pp. 6 https://arxiv.org/pdf/1112.1368.pdf // modified to keep from crashing :) divisions replaced with multiplication :)
      setLimits(0, 32, 0, 32, 0, 32);
      result = t >> c |  t & (  ( t >> 5 ) / ( t >> b * 4 - ( t >> a / 3 ) & - t >> b / 4 - ( t >> a / 3 ) ) );
      // t >>4 | t &(( t >> 5 )/( t >> 7 − ( t >> 15 ) & − t >> 7 − ( t >> 15 ) ) )
      break;
    case 9:  // variation t+(t&1)+(t>>5)*(t>>1)/1|t>>4|t>>8  nice bass drones with whirring open hats? or damped cymbals https://dollchan.net/btb/res/3.html#258
      setLimits(4, 37, 0, 16, 5, 12);
      result = ( t + ( t & b) + ( t >> a ) * ( t >> b ) / 1 | t >> b | t >> c );
      break;
    case 10: // scratch percussion on th extreme (try * c)
      setLimits(1, 68, 1, 68, 0, 32);
      bb37_set(a, b);
      result =  bb37() & t >> c;
      break;
    case 11: // 5824 hz is nice. quaks like a duck
      setLimits(1, 16, 1, 16, 0, 32);
      bb22_set(a, b);
      result =  bb22() - c ;
      break;
    case 12:     // Nightmachines https://forum.aemodular.com/post/235 ( t*4|t|t>>3&t+t/4&t*12|t*8>>10|t/20&t+140)&t>>4
      setLimits(3, 8, 8, 16, 20, 30);
      result  = (t * 4 | t | t >> a & t + t / 4 & t * 12 | t * 8 >> b | t / c & t + 140) & t >> 4;
      break;
    case 13: // droid http://www.pouet.net/topic.php?which=8357&page=10#c388999
      setLimits(3, 8, 3, 8, 3, 8);
      result = t >> a & 1 ? t >> b : -t >> c;

      break;
    case 14:  // poetaster this is great with a modulator like the kastle.
      // belongs in musical
      setLimits(0, 8, 0, 8, 0, 8);
      result = ( t % 16 ? t >> a & t >> 7 : t >> 11 & t >> b ) * ( t % 8 ? ~t >> 9 & b : ~t >> 11 & c ) & 64 ;
      break;
    case 15:  // https://forum.arduino.cc/t/one-line-algorithmic-music/73409
      // (t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))
      setLimits(0, 16, 0, 16, 0, 16);
      result =  ( t & (a * 16) ? ( t * ( t ^ t % (b * 8) ) | t >> a ) >> 127 : t >> b | ( t & (c * 32) ? t << c : t ) )   ;
      break;
    case 16: // started with vizmut paper pp. 6 https://arxiv.org/pdf/1112.1368.pdf // modified to keep from crashing :) divisions replaced with multiplication :)
      // belongs in musical
      setLimits(0, 16, 0, 16, 0, 16);
      result = t >> c | t | (( t >> 5 ) / ( t % 2 ? t >> b / 2 : t >> b)) | ( t % 3 ? t >> a / 3 : t >> a );
      break;
    case 17: // nice
      setLimits(1, 68, 1, 68, 1, 32);
      bb34_set(a, b);
      result =  bb34() * c; // or - c
      break;
    case 18:// ola http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html?showComment=1318368575135#c8615755234789420078
      //2*(1-(t+10>>(t>>9&t>>14)&t>>4&-2))*((t>>10^t+(t>>6&127)>>10)&1)*32+128
      setLimits(4, 16, 4, 16, 4, 12);
      result = 2 * (1 - (t + 10 >> (t >> a & t >> b)&t >> c & -2)) * ((t >> 10 ^ t + (t >> 6 & 127) >> 10) & 1) * 32 + 128;
      break;
    case 19:// https://www.pouet.net/topic.php?post=589098
      setLimits(1, 11, 1, 11, 1, 11);
      result = t * (0xC298C298C298 >> (t >> a)&t >> b)&t >> c;
      break;
    case 20: // FIX rythm straight rythmic, great range! // tejeez 2011-10-05 #countercomplex
      setLimits(1, 16, 1, 16, 0, 16);
      result = ( ~t >> 2) * ((127 & t * (b & t >> 10)) < (245 & t * (2 + (c & t >> a))));
      break;
    case 21:  //  FIX rythm? Street Surfer by skurk, raer (2011-09-30) https://www.pouet.net/topic.php?which=8357&page=4#c388479
      setLimits(1, 16, 1, 16, 0, 16);
      result  = t & (4096) ? t / 2 * (t ^ t % (a << 1)) | t >> 5 : t / (a << 1) | (t & (b << 7) ? 4 * t : t);
      //enc_offset =  20;
      break;
    case 22://https://www.pouet.net/topic.php?post=587236 ((t*((t>>12)^((t>>12)-1)))&(t>>5)^(t>>6))+t+128
      setLimits(1, 5, 1, 9, 8, 16);
      result = ((t * ((t >> c) ^ ((t >> c) - 1))) & (t >> a) ^ (t >> b)) + t + 128;
      break;
    case 23:      // harism http://viznut.fi/demos/unix/bytebeat_formulas.txt
      setLimits(1, 8, 1, 16, 16, 24);
      result  = a * ((t >> b) + 20) * t >> 14 * t >> c >> t;

      break;
    case 24: // drums where did this come from?
      setLimits(0, 36, 0, 16, 10, 20);
      // a 18, b 6, c 10
      //int u = 0;
      //result = ((((u = t & 0xfff) & 0 + ((u + 1 << (a + (t >> c & 1 * b))) / u) & 255) / (u >> 8)) & 240 - 128) * 3;

      break;

    case 25:  // poetaster helicopters has some arps with b in the middle, various! can also humm with bells.
      setLimits(8, 24, 1, 16, 1, 16);
      result = ( (t >> a) - ( t >> a & t )  + ( t >> t &  b ) ) + ( t * ((t >> c) & c ) );
      break;
    case 26:   // poetaster windy whirls, noisy swirls, ocean swells, drop off. revisit since it funks as
      setLimits(1, 12, 1, 16, 1, 16);
      result =  t >> ( ( a + 1 )  & b & t >> 8 ) ^ ( t & t >> a | t >> c ); /// maybe t >> 16?

      break;
    case 27:  // poetaster breaky, jungle stuff a at one oclock, c middle, etc
      setLimits(1, 12, 1, 16, 1, 16);
      if (t > 65536) t = -65536;
      result = a + ( ( t >> a + 1 ) ) * (t >> c | b | t >> ( t >> 16) )  ;
      break;
    case 28:  // poetaster techno stuff but slow it down and it's rockin
      setLimits(1, 8, 1, 10, 1, 10);
      result =  (t & t >> b | t << b >> c) ^ ( t  &  t >> a | t << a >> b) & ( t & t >> c | t << c >> a);
      break;
    case 29: // poetaster counter point bleeps with a hihat or reverb stuff NAH at 2 times medlodic
      setLimits(4, 16, 4, 16, 1, 8);
      result =  ( t  &  t >> c | t + c << 4) | (t & t >> a | t + a << 3) ^ ( t & t >> b | t + b << 2 );

      break;
    case 30: // poetaster - sound fx wroom zoom ..... goes long not like th original nice variety http://www.pouet.net/topic.php?which=8357&page=17#c389829",
      // (t*(t>>12)*64+(t>>1)*(t>>10)*(t>>11)*48)>>(((t>>16)|(t>>17))&1
      setLimits(1, 30, 1, 15, 1, 15);
      result = ( t * (t >> c) * 64 + ( t >> 1 ) * ( t >> b ) * (t >> 7) * 48 ) >> ( ( (t >> 16) | (t >> a) ) + 1);
      break;
    case 31:   // poetaster c high, techno wheep, b pitch in the middle, a patterned blips fast to slow
      setLimits(1, 24, 1, 12, 1, 16);
      result =  t * ( t >> b & ( t >> b ? 13 : 8)  ) - t >> c ^ t & 21 | t + (t ^ t >> a)  ^ t << 1 & (t & a ? t >> 5 : t >> 3);
      break;
    case 32:  // poetaster descending / ascending bleep arps, lasers, a high bass run
      result = t - ((t & ((t >> a))) + ( a | t >> c )) & (t >> ( c + 1)) | (t >> b) & (t * (t >> a));
      break;
    case 33:  // poetaster also a drone, but melodic basic with perc blurbs hh hits goes to techno with 3 part development
      setLimits(4, 16, 3, 16, 1, 16);
      result =  ( t >> a | t - b ) & ( t - a | t >> b ) * c;

      break;
    case 34:   // started with vizmut paper pp. 5 https://arxiv.org/pdf/1112.1368.pdf = hacked to bits :)
      setLimits(2, 100, 2, 50, 2, 10);
      result = t - b & ( ( t >> a | t >> b ) ) ^ t - c & ( ( t >> b | t << c * 2 ) ) ^ t - a & ( ( t >> c | t >> 3 ) ) ;

      break;
    case 35:    // started with vizmut paper pp. 6 https://arxiv.org/pdf/1112.1368.pdf
      setLimits(1, 16, 1, 16, 1, 16);
      result = t - b & ( (t >> a | t << 4 ) ) ^ t - c & ( ( t >> b | t << 3 ) ) ^ t - a & ( ( t >> c | t << 2 ) ) ;

      //result = (int)(t/1e7 * t * t + c ) % 127 | t >> c ^ t >> b | t % 127 + ( t >> a ) | t ;
      break;
    // the bb funcs are from nyblybyte.h
    case 36:  // b39 crashes? or just really slow? bb39 is nice but no go
      setLimits(1, 68, 1, 68, 0, 32);
      bb19_set( a, b);
      result =  bb19() | t >> c ;
      break;
    case 37: // it evolves noisy. lots of breaks to silence
      setLimits(1, 68, 1, 68, 1, 16);
      bb28_set(a, b);
      result =  bb28() |  ~t << c;
      break;
    case 38: // yeah, it's nice and evolves a lot :)
      setLimits(1, 68, 1, 68, 0, 32);
      bb17_set(a, b);
      result =  bb17() | t >> c;
      break;
    case 39: // no needs 8000 hz and takes a while // actually melodic
      setLimits(1, 16, 1, 16, 0, 32);
      bb23_set(a, b);
      result =  bb23() - c;
      break;
    case 40:// ?? borked
      setLimits(1, 16, 1, 16, 0, 16);
      bb33_set(a, b);
      result =  bb33() >>  c;
      break;
    case 41: // bit boring :) //https://www.blogger.com/profile/02935728280207314233
      setLimits(0, 8, 0, 8, 0, 8);
      result = (t < 16384) ? (t * a & t * 2 >> b) : (t < 32768) ? (t * a & t * 2 >> c) : (t < 49152) ? (t * (b)&t * 2 >> a) : (t < 65536) ? (t * (b)&t * 2 >> c) : 0 ;
      if (t >= 65536)t = 0;
     ;
    case 42:  // poetaster a synth lead with breaks, and stuff :) c 12 oclock and it starts being a wave form
      setLimits(1, 16, 21, 63, 0, 16);
      result = (t >> 3 ? b : a) * t >> c ^ t % c | t + (t ^ t >> a) ;

    case 43:  // poetaster mad techno helicopter bird flock this is an evil hack.
      setLimits(1, 16, 1, 16, 0, 16);
      result =    ( t / ( a * b ) ) & ( ( t >> a ) & t >> b ) * ( t << c) + a ^ ( t >> (t / b ) ) ;//^ ( t >> ( 16 * c ) ) ;

      break;
    case 44:  // poetaster clicky burpy can do techno ! it's great when you find it ;)
      setLimits(0, 15, 0, 11, 0, 9);
      result = ( ( (t >> 9 ? a : b) & t * (t >> b) % (t >> c) - (t >> b) ) * (t >> a) ) ;
      break;
  }
}

// https://forum.arduino.cc/t/one-line-algorithmic-music/73409
//      // (t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))
// https://www.pouet.net/topic.php?post=394926
//int z = 0;
//      result = (z=(t>>(1+(t>>13&1))) * (t>>15 & 0xfd) * (t >> 11 & 0xdf) * (t >> 7 & 0xcc))*0+((t<<1))&z | ((t<<2))&z;

void melodious(int pb2) {

  switch (pb2) {
    case 1:  // isislovecruft https://www.noisebridge.net/wiki/Bytebeat
      //(~t>>2)*(2+(42&2*t*(7&t>>10))<(24&t*((3&t>>14)+2)))
      setLimits(36, 72, 16, 64, 1, 16);
      result = (~t >> 2) * (2 + (a & 2 * t * (7 & t >> 10)) < (b & t * ((3 & t >> c) + 2)));
      break;
    case 2: // wiretapped https://www.noisebridge.net/wiki/Bytebeat (1+(t>>10)%7)*(t*(1+(t>>13)%4)%(24+9*(t>>14)%8)&16)*10
      setLimits(4, 16, 21, 32, 8, 20);
      result = (1 + (t >> 10) % 7) * (t * (1 + (t >> a) % 4) % (b + 9 * (t >> c) % 8) & 16) * 10;
      break;
    case 3: // wiretapped, too u11*(t*(1|(t>>10-(t>>17)%4)%8)&(8<<(t>>13)%4)*(1|(t>>15)%8))*(t>>10)
      setLimits(1, 10, 1, 8, 1, 16);
      result = 11 * (t * (1 | (t >> a - (t >> 17) % b) % c) & (8 << (t >> 13) % b) * (1 | (t >> 15) % 8)) * (t >> 10);
      break;
    case 4:  //VISMUT  https://forum.arduino.cc/t/one-line-algorithmic-music/73409
      // (t * (4 |t >> 13 & 3 ) >> ( ~t >> 11 & 1)  & 128  | t * ( t >> 11 & t >> 13 ) * ( ~t>> 9 & 3 ) & 127 ) ^ ( t & 4096 ? ( t * ( t ^ t % 255 ) | t >> 4 ) >> 1 : t >> 3 |( t &8192 ? t << 2 : t ) )
      pb2 = 5;
      setLimits(1, 13, 1, 15, 1, 11);
      result = (t * (4 | t >> 13 & b ) >> ( ~t >> 11 & 1 ) & 128 | t * ( t >> a & t >> 13 ) * ( ~t >> c & 3 ) & 127 ) ^ ( t & 4096 ? ( t * ( t ^ t % 255 ) | t >> 4 ) >> 1 : t >> 3 | ( t & 8192 ? t << 2 : t ) );
      break;
    case 5:// RYTHM !https://www.pouet.net/topic.php?post=587236 (115|t)* (256 - (t>>(9 - 2*((t>>14)%2) )) ) * ((256-(t>>4)%256))/256
      setLimits(1, 11, 1, 11, 1, 11);
      result = t * (0xC298C298C298 >> (t >> a)&t >> b)&t >> c;
      break;
    case 6: // variation on 45 MAKE this TWO
      setLimits(0, 32, 0, 32, 0, 32); // aMin, aMax, etc
      result = ( ~t >> 2 ? ~t >> 3 : ~t >> 2) * ( (127 & t * ( b & t >> 10) ) < (245 & t * ( 2 + ( c & t >> a ) ) ) );

      break;
    case 7:  // variation on 45 MAKE this ONE
      setLimits(0, 32, 0, 32, 0, 32); // aMin, aMax, etc
      result = ( ~t >> 7 ? ~t >> 3 : ~t >> 4) * ( (245 & t * ( b & t >> 10) ) < (127 & t * ( 2 + ( c & t >> a ) ) ) );
      break;
    case 8: //t*(t>>9&10|t>>11&24^t>>10&15&t>>15) http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html?showComment=1317761042403#c4044676811126652266
      setLimits(4, 16, 8, 16, 8, 24); // aMin, aMax, etc
      result = t * (t >> a & 10 | t >> b & 24 ^ t >> 10 & c & t >> 15);
      break;
    case 9:  // poetaster long distorted carnival number
      pb2 = 10;
      setLimits(1, 12, 1, 16, 1, 16);
      result = (t * a & t >> b | t * c & t >> 7 | t * 3 & t / 1024) - 1;

      break;
    // maybe also in rythmical?
    case 10:  // poetaster twisted calliope distortion can rock :)
      setLimits(1, 30, 1, 15, 1, 15);
      result = (  t * b & c / (a << 2) | t * b & t >> c | t * ( c + b ) & t >> a) - 1;

      break;
    case 11: // funny melody! and arps.  http://www.pouet.net/topic.php?which=8357&page=9#c388930",
      setLimits(1, 16, 1, 16, 0, 32);
      result =   ( t * ( ( a + ( 1 ^ t >> 10 & b ) ) * ( b + ( a & t >> 14 ) ) ) ) | ( t >> c  );
     ;
      break;
    case 12: // FIX rythm, broken poetaster fast to slow arps + staccato noise and robot voice = breaks with 9 o'clock, 5 to 12 o'clock, 3 o'clock
      setLimits(0, 64, 0, 16, 0, 16);
      result = (( t >> c | t << b ) & (a + 1))  * (( t >> (b + 1) ) | t >> ( t << 21)) ;
      break;
    case 13:  // poetaster pulse drone // seems to kill the nano after all?
      setLimits(1, 32, 1, 24, 1, 16);
      result = ((t * a) & ( t >> 5 | t << 2 )  ) | ( (t * b) & ( t >> 4 | t << 3)) | ((t * c) & ( t >> 3 | t << 4 ) );
      break;
    case 14:  // beyon http://countercomplex.blogspot.com/2011/10/algorithmic-symphonies-from-one-line-of.html?showComment=1318081308422#c4945456935852459432
      setLimits(8, 16, 7, 14, 6, 12);
      result = t >> 6 ^ t & 37 | t + (t ^ t >> a) - t * ((t % 24 ? 2 : 6)&t >> b)^t << 1 & (t & 598 ? t >> 4 : t >> c);
      break;
    case 15:  // poeaster variation with melodic with shells  variation on https://dollchan.net/btb/res/3.html#78
      // ( ( t >> 10 | t * 5 ) & ( t >> 8 | t * 4 ) & ( t >> 4 | t * 6 ) );
      setLimits(0, 16, 0, 8, 0, 16);
      result = ( ( t >> a | t * 5 ) & ( t >> ( a + 2 ) | t * b ) & ( t >> b | t * c ) );

      break;
    case 16: // try * c? but nice and rockin the way it is.
      setLimits(1, 68, 1, 68, 0, 32);
      bb32_set(a, b);
      result =  bb32() | t >> c;

      break;
    case 17:
      setLimits(1, 68, 1, 68, 0, 32);
      bb8_set(a, b);
      result =  bb8() | t >> c;
      break;
    case 18: // pad melodies 2 & 3 part with noise crackle on c
      setLimits(1, 68, 1, 68, 0, 32);
      bb35_set(a, b);
      result =  bb35() - c ;

      break;
    case 19: // same as 49 origin. more 4/4 tech qwowloon wow.
      setLimits(1, 32, 1, 32, 1, 32);
      result =   (t * ((3 + ( 1 ^ t >> a & 5 ) ) * ( 5 + ( 3 & t >> b ) ) ) ) >> ( t >> c & 3 );

      //result = t >> c ^ t & 1 | t + (t ^ t >> 13) - t * ((t >> 5 ? b : a) & t >> ( 8 - ( a >> 1 )  ) );
      break;
    case 20:   // poetaster drone, organ, perc
      setLimits(1, 8, 1, 16, 1, 8);
      result = ( ( t * a & t >> 4 ) | ( t * b & t >> 7 ) | ( t * c &  t) ) - ( t >> b ? 13 : 8)   ;

      break;
    case 21: // http://entropedia.co.uk/generative_music/#v3b64K0otKS3KU9AoUdMosbMz09TWKLGx0QCxDQ014yAMY01tY03NGgjHRNXMBKQKxNTU1FTT0AUyTTU1rRX0tRRCihKTsxWcixLTSioVkioVAhJLcxQ8EitTixW09AE=
      setLimits(1, 8, 11, 16, 1, 24);
      result = (t & (t >> 6) + (t << ((t >> 11) ^ ((t >> b) + a)) | ((t >> c % 64) + (t >> c))) & (-t >> 5));
      //result = (t&(t>>6)+(t<<((t>>11)^((t>>13)+3))|((t>>14%64)+(t>>14)))&(-t>>5));
      break;
case 22:  https://www.pouet.net/topic.php?post=394926
      // (t*(4|t>>13&3)>>(~t>>11&1)&128|t*(t>>11&t>>13)*(~t>>9&3)&127)^(t&4096?(t*(t^t%255)|t>>4)>>1:t>>3|(t&8192?t<<2:t))
      setLimits(7, 13, 9, 15, 3, 11);
      result = (z = (t >> (1 + (t >> a & 1))) * (t >> a & 0xfd) * (t >> c & 0xdf) * (t >> 7 & 0xcc)) * 0 + ((t << 1))&z | ((t << 2))&z;
      break;
    case 23: // t>>4|t*t*(t>>6&8^8)*(t>>11^t/3>>12)/(7+(t>>10&t>>14&3)) https://www.pouet.net/topic.php?post=401683
      setLimits(11, 24, 10, 24, 14, 24);
      result = t >> 4 | t * (t >> 6 & 8 ^ 8) * (t >> a ^ t / 3 >> 12) / (7 + (t >> b & t >> c & 3));
      break;
    case 24://https://www.pouet.net/ ((t>>6)&(t<<3)/(t*(t>>11)%(3+((t>>16)%22))))
      setLimits(1, 9, 1, 5, 8, 16);
      result = ((t >> a) & (t << 3) / (t * (t >> 11) % (3 + ((t >> c) % (b * 11)))));

      break;
    case 25://https://www.pouet.net/topic.php?post=587236 (t>>(4+(1&t>>(5*(1+(t>>(11-(1&t>>(11+(1&t>>13))))))))))
      setLimits(1, 5, 11, 22, 11, 16);
      result = (t >> (4 + (a & t >> (5 * (a + (t >> (11 - (1 & t >> (b + (a & t >> c))))))))));
      break;
    case 26://https://www.pouet.net/topic.php?post=401561
      if (t > 65536) t = -65536;
      setLimits(1, 9, 1, 9, 9, 15);
      //8*t*t*(t>>(t>>10)%3+15)/(3+(t>>10&(t>>15&3|4)))|t/16
      //result = 8*t*t*(t>>(t>>(a*10))%3+c)/(3+(t>>(a*10)&(t>>c&a|b)))|t/16;
      result = 8 * t * (t >> (t >> 10) % 3 + c) / (3 + (t >> 10 & (t >> c & a | b))) | t / 16;
      break;
    case 27: // glitch https://www.reddit.com/r/bytebeat/comments/ufvuio/electricity/ 12 / 16 / 12
      setLimits(8, 24, 8, 32, 8, 24);
      result = (t >> 12 & 3 ? ((t >> a) % ((t >> b) % 6 / (3 & t >> c) + 1) + 1) * t & -t >> 4 : ((t >> 1) % ((t >> b) % 6 / (3 & t >> a) + 1) + 1) * t & t); // +5E3/(t/4&4095);
      break;
    case 28:
      // wavetable sine. could probably add a bunch of (t&15)*(-t&15)*(((t&16)/8)-1)*128/65+128
      setLimits(1023, 0, 1023, 0, 1023, 0);
      tune = 404 - a;
      tune = tune << 3;
      freq[0] = a + tune;
      freq[1] = b + tune;
      freq[2] = c + tune;
      Acc[0] += freq[0];
      Acc[1] += freq[1];
      Acc[2] += freq[2];
      result = ( pgm_read_byte(&sine256[Acc[1] >> 8]) + pgm_read_byte(&sine256[Acc[2] >> 8]) ) / 2;
      break;
    case 29: //saw phase in honour of https://ressources.labomedia.org/_media/bytebeats_beginners_guide_ttnm_v1-5.pdf
      setLimits(48, 72, 32, 64, 8, 48);
      result = t % a | t % b | t % c;
      break;



      /*
        case 17: // 216  t*(t^t+(t>>15|1)^(t-1280^t)>>10); http://viznut.fi/demos/unix/bytebeat_formulas.txt
        setLimits(1, 9, 12, 18, 320, 640);
        result = t * (t ^ t + (t >> b | a) ^ (t - c ^ t) >> 10);
        break;
        case 20: //poetaster requires 4* normal speed // does not seem to work
        setLimits(32, 39, 32, 47, 32, 58);
        result = t * ( ( ( t >> 11 * a / 27 ) & ( ( t >> 11 * b / 27 ) - 1 ) ^ 7) * 11 * c / 27);
        //result = t * ( ( ( t%2? t>>11*a/27: t>>11*a/9 ) ^ ( ( t >> 11*b/9 ) - 1 ) ^ 7) ^ 11*c/9);
        break;*/
      /*
        case 22:  // xpansive 2011-09-29 https://www.pouet.net/topic.php?which=8357&page=3#c388375
        // t * (t >> 8 | t >> 9) & 46 & t >> 8 ^ (t & t >> 13 | t >> 6);
        setLimits(40, 56, 1, 9, 0, 16);
        result = t * (t >> 8 | t >> 9) & a & t >> 8 ^ (t & t >> c | t >> b);
        break;
      */
      /*
        case 24: // https://www.pouet.net/topic.php?post=401900 (z=3*t>>t/4096%4&-t%(t>>16|16)*t>>14&8191)/(z>>6|1)*4;
        setLimits(1, 7, 1, 9, 11, 24);
        result = (z = b * t >> t / 4096 % 4 & -t % (t >> c | c) * t >> 14 & 8191) / (z >> 6 | a) * 4;
        break;
      */


  }

}
