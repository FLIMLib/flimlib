/*
 * #%L
 * SLIM Curve package for exponential curve fitting of spectral lifetime data.
 * %%
 * Copyright (C) 2010 - 2015 University of Oxford and Board of Regents of the
 * University of Wisconsin-Madison.
 * %%
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/gpl-3.0.html>.
 * #L%
 */

/* 
Main.cpp for the stand alone executable version of SLIM Curve via the C++ interface.

*/

#include "slim-curve.hpp"

// Test Data
float transient[] = {43, 39, 50, 46, 56, 63, 62, 74, 60, 72, 58, 47, 41, 69, 69, 58, 55, 37, 55, 50, 52, 59, 51, 52, 51, 50, 53, 40, 45, 34, 54, 44, 53, 47, 56, 62, 66, 82, 90, 108, 122, 323, 1155, 4072, 8278, 11919, 13152, 13071, 12654, 11946, 11299, 10859, 10618, 10045, 9576, 9208, 9113, 8631, 8455, 8143, 8102, 7672, 7384, 7463, 7254, 6980, 6910, 6411, 6355, 6083, 5894, 5880, 5735, 5528, 5343, 5224, 4933, 5026, 4914, 4845, 4681, 4426, 4485, 4271, 4295, 4183, 3989, 3904, 3854, 3801, 3600, 3595, 3434, 3457, 3291, 3280, 3178, 3132, 2976, 2973, 2940, 2770, 2969, 2851, 2702, 2677, 2460, 2536, 2528, 2347, 2382, 2380, 2234, 2251, 2208, 2115, 2136, 2000, 2006, 1970, 1985, 1886, 1898, 1884, 1744, 1751, 1797, 1702, 1637, 1547, 1526, 1570, 1602, 1557, 1521, 1417, 1391, 1332, 1334, 1290, 1336, 1297, 1176, 1189, 1220, 1209, 1217, 1140, 1079, 1059, 1074, 1061, 1013, 1075, 1021, 1012, 940, 982, 866, 881, 901, 883, 893, 845, 819, 831, 758, 794, 779, 772, 779, 791, 729, 732, 687, 690, 698, 661, 647, 668, 642, 619, 629, 656, 579, 579, 600, 563, 584, 531, 554, 526, 484, 530, 515, 493, 502, 479, 445, 439, 466, 431, 423, 451, 412, 415, 393, 404, 390, 398, 352, 394, 376, 338, 377, 367, 355, 352, 375, 339, 347, 316, 295, 322, 311, 294, 304, 264, 293, 294, 283, 278, 302, 253, 259, 252, 278, 254, 245, 246, 242, 226, 241, 222, 198, 197, 245, 221, 228, 224, 216, 174, 166, 163, 127, 122 };
const int ndata = 256;
int fit_start = 45;
int fit_end = 200;
float instr[] = { 0.00911042f, 0.0388225f, 0.131711f, 0.252389f, 0.27723f, 0.180233f, 0.0792762f, 0.0312277f };
const int ninstr = 8;
float xincr = 0.058628749f;

// Test return values
float params[MAXFIT] = { 0 };
float fitted[ndata];
float residuals[ndata];
float chisq;

/* Entry point
*/
int main(int argc, const char * argv[])
{
	// Create a fitter
	SLIMCurve SlimCurve;

	// Load up the fitter inputs
	SlimCurve.transient = transient;
	SlimCurve.ndata = ndata;
	SlimCurve.fit_start = fit_start;
	SlimCurve.fit_end = fit_end;
	SlimCurve.instr = instr;
	SlimCurve.ninstr = ninstr;
	SlimCurve.xincr = xincr;
	SlimCurve.param = params;   // starting values, will contain the fitted values at end of fit.

	// Assign the fitter Outputs
	SlimCurve.fitted = fitted;
	SlimCurve.residuals = residuals;
	SlimCurve.chisq = &chisq;

	// Run the fit function
	SlimCurve.fitRLD();

}
