#pragma once
#include<Windows.h>

class RGBINFO {
public:
	INT nR = 0;
	INT nG = 0;
	INT nB = 0;
	BOOL bValid = FALSE;

	BOOL operator ==(RGBINFO &rgb2) {
		return nR == rgb2.nR && nG == rgb2.nG && nB == rgb2.nB && bValid == rgb2.bValid;
	}

	BOOL operator !=(RGBINFO &rgb2) {
		return nR != rgb2.nR || nG != rgb2.nG || nB != rgb2.nB || bValid != rgb2.bValid;
	}
};