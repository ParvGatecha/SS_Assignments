package com.parvgatecha.esdfirstapp.mapper;

import com.parvgatecha.esdfirstapp.dto.ProductRequest;
import com.parvgatecha.esdfirstapp.entity.Product;
import org.springframework.stereotype.Service;

@Service
public class ProductMapper {
    public Product toProduct (ProductRequest request) {
        return Product.builder()
                .name(request.name())
                .price(request.price())
                .build();
    }
}
