package com.parvgatecha.esdfirstapp.service;

import com.parvgatecha.esdfirstapp.dto.ProductRequest;
import com.parvgatecha.esdfirstapp.entity.Product;
import com.parvgatecha.esdfirstapp.helper.JWTHelper;
import com.parvgatecha.esdfirstapp.mapper.ProductMapper;
import com.parvgatecha.esdfirstapp.repo.ProductRepo;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
@RequiredArgsConstructor
public class ProductService {
    private final ProductRepo productRepo;
    private final JWTHelper jwtHelper;
    private final ProductMapper productMapper;

    public List<Product> getAllProducts() {
        return productRepo.findAll();
    }

    public String addProduct(ProductRequest product) {
        Product product1 = productMapper.toProduct(product);
        productRepo.save(product1);
        return "Product added";
    }

    public Product getProduct(String name) {
        Product product = productRepo.findByName(name).orElse(null);
        return product;
    }

    public String updateProduct(ProductRequest product) {
        Product productt = getProduct(product.name());
        productt.setPrice(product.price());
        productRepo.save(productt);
        return "Product updated";
    }

    public String deleteProduct(String name) {
        Product product = productRepo.findByName(name).orElse(null);
        productRepo.delete(product);
        return "Product deleted";
    }

    public String getProductsWithPriceRange(String low, String high) {
        List<Product> products = productRepo.findTop2ByPriceBetweenOrderByPriceAsc(low,high);
        StringBuilder pro = new StringBuilder();
        for(Product product : products) {
            pro.append(product.getName()).append(",");
        }
        return pro.toString();
    }
}
