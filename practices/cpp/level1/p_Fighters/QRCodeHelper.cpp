//
// Created by wxdao on 16-5-13.
//

#include <zint.h>
#include <cstring>
#include "QRCodeHelper.h"

QRCodeHelper::QRCodeHelper(std::string content) {
    this->content = content;
}

void QRCodeHelper::setContent(std::string content) {
    this->content = content;
}

void QRCodeHelper::render(sf::Texture &texture) {
    zint_symbol *symbol = ZBarcode_Create();
    std::string fn = "res/tmp.png";
    symbol->symbology = BARCODE_QRCODE;
    strcpy(symbol->outfile, fn.c_str());
    ZBarcode_Encode_and_Print(symbol, (unsigned char *) content.c_str(), (int) content.length(), 0);
    texture.loadFromFile(fn);
    ZBarcode_Delete(symbol);
    remove(fn.c_str());
}

