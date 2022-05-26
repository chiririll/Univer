#include "ProductCreator.h"

string CheckFields(const string fields_names[], int fields_count, const vector<string> &fields) {
    if (fields.size() >= fields_count) 
        return "";

    string error = "Not enough fields: ";
    
    for (int i = fields.size(); i < fields_count; i++) {
        error = error + fields_names[i];
        error = error + ", ";
    }
    error.erase(error.length() - 2, 2);

    return error;
}

Product* ProductCreator::CreateProduct(const vector<string> &fields) {
    const string fields_names[] = {"Type", "Label", "Price", "Quantity", "Production date"};
    const int fields_count = 5;

    ProductData product_data;
    string error = "";
    int pos;

    // Missing fields
    error = CheckFields(fields_names, fields_count, fields);
    if (!error.empty()) {PushError(error); return NULL;}

    // Id
    product_data.id = 0;

    // Label
    pos = 1;
    product_data.label = fields[pos];

    // Price
    pos = 2;
    error = str_to_int(fields_names[pos], fields[pos], product_data.price);
    if (!error.empty()) {PushError(error); return NULL;}
    
    // Quantity
    pos = 3;
    error = str_to_double(fields_names[pos], fields[pos], product_data.quantity);
    if (!error.empty()) {PushError(error); return NULL;}
    
    // Production Date
    pos = 4;
    error = parse_date(fields_names[pos], fields[pos], product_data.production_date);
    if (!error.empty()) {PushError(error); return NULL;}
    
    // Other fields
    vector<string> other_fields;
    other_fields.resize(fields.size() - fields_count);
    std::copy(fields.begin() + fields_count, fields.end(), other_fields.begin());

    // Creating product
    const string &type = fields[0];
    if (type == "beer")
        return CreateBeer(product_data, other_fields);
    if (type == "vodka")
        return CreateVodka(product_data, other_fields);
    if (type == "wine")
        return CreateWine(product_data, other_fields);

    PushError("Unknown product type '" + type + "'");
    return NULL;
}

Product* ProductCreator::CreateBeer(ProductData data, const vector<string> &fields) {
    const string fields_names[] = {"Expiration date", "Warehouse capacity"};
    const int fields_count = 2;

    string error = "";

    // Missing fields
    error = CheckFields(fields_names, fields_count, fields);
    if (!error.empty()) {PushError(error); return NULL;}

    // Expiration Date
    std::tm expiration_date;
    error = parse_date(fields_names[0], fields[0], expiration_date);
    if (!error.empty()) {PushError(error); return NULL;}

    // Warehouse capacity
    double warehouse_capacity;
    error = str_to_double(fields_names[1], fields[1], warehouse_capacity);
    if (!error.empty()) {PushError(error); return NULL;}

    return new Beer(data, expiration_date, warehouse_capacity);
}

Product* ProductCreator::CreateVodka(ProductData data, const vector<string> &fields) {
    const string fields_names[] = {"Warehouse capacity"};
    const int fields_count = 1;
    
    string error = "";

    // Missing fields
    error = CheckFields(fields_names, fields_count, fields);
    if (!error.empty()) {PushError(error); return NULL;}

    // Warehouse capacity
    double warehouse_capacity;
    error = str_to_double(fields_names[0], fields[0], warehouse_capacity);
    if (!error.empty()) {PushError(error); return NULL;}

    return new Vodka(data, warehouse_capacity);
}

Product* ProductCreator::CreateWine(ProductData data, const vector<string> &fields) {
    return new Wine(data);
}
