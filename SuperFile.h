#pragma once

#include <stdio.h>
#include "Supermarket.h"

int	saveSuperMarketToFile(const SuperMarket* pMarket, const char* fileName,
	const char* customersFileName,int compressFlag);
int	saveCustomerToTextFile(const SuperMarket* pMarket, const char* customersFileName);
int	loadSuperMarketFromFile(SuperMarket* pMarket, const char* fileName, const char* customersFileName, int Compressedflag);
int saveSupermarketDataCompress(const SuperMarket* pMarket, FILE* fp);
int	loadCustomerFromTextFile(SuperMarket* pMarket, const char* customersFileName);


int readSupermarketDataCompress(SuperMarket* pMarket, FILE* fp);


int	loadProductFromTextFile(SuperMarket* pMarket, const char* fileName);
