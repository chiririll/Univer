#include "ProductCreator.h"

Product* ProductCreator::CreateProduct(const vector<string> &fields) {
    string fields_names[] = {"Type", "Label", "Price", "Quantity", "Production date"};

    ProductData product_data;
    string error = "";

    if (fields.size() < 5) {
        error = "Not enough fields: ";
        
        for (int i = fields.size(); i < 5; i++)
            error += fields_names[i] + ", ";
        error.erase(error.length() - 2, 2);

        PushError(error);
        return NULL;
    }

    // Label
    product_data.label = fields[1];

    // Price
    error = try_to_cast(fields_names[2], fields[2], product_data.price, std::stoi);
    if (!error.empty()) {PushError(error); return NULL;}
    
    // Quantity
    error = try_to_cast(fields_names[3], fields[3], product_data.quantity, std::stod);
    if (!error.empty()) {PushError(error); return NULL;}
    
    // Production Date
    // fields[4] >> std::get_time(product_data.production_date, "yyyy-mm-dd");

    // Quantity
    try {
        product_data.quantity = stod(fields[3]);
    } catch (std::invalid_argument const& ex) {
        PushError("Invalid quantity: " + fields[3]);
        return NULL;
    } catch (std::out_of_range const& ex) {
        PushError("Quantity is very big: " + fields[3]);
        return NULL;
    }

    // Production date
    // TODO
    

    /*if (fields[0] == "beer")
        return CreateBeer(fields);
    if (fields[0] == "vodka")
        return CreateVodka(fields);
    if (fields[0] == "wine")
        return CreateWine(fields);*/
    
    PushError("Unknown product type '" + fields[0] + "'");
    return NULL;
}

Product* ProductCreator::CreateBeer(ProductData data, const vector<string> &fields) {
}

Product* ProductCreator::CreateVodka(ProductData data, const vector<string> &fields) {
    
}

Product* ProductCreator::CreateWine(ProductData data, const vector<string> &fields) {
    
}