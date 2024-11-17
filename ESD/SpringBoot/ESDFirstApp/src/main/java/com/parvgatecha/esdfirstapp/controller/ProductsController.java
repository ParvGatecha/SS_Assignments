package com.parvgatecha.esdfirstapp.controller;

import com.parvgatecha.esdfirstapp.dto.ProductRequest;
import com.parvgatecha.esdfirstapp.entity.Product;
import com.parvgatecha.esdfirstapp.service.ProductService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequiredArgsConstructor
@RequestMapping("api/v1/products")
public class ProductsController {
    private final ProductService productService;

    @GetMapping
    public ResponseEntity<List<Product>> getAllProducts() {
        return ResponseEntity.ok(productService.getAllProducts());
    }

    @PostMapping
    public ResponseEntity<String> addProduct(@RequestBody ProductRequest product) {
        return ResponseEntity.ok(productService.addProduct(product));
    }

    @GetMapping("/{name}")
    public ResponseEntity<Product> getProduct(@PathVariable String name) {
        return ResponseEntity.ok(productService.getProduct(name));
    }

    @PutMapping()
    public ResponseEntity<String> updateProduct(@RequestBody ProductRequest product) {
        return ResponseEntity.ok(productService.updateProduct(product));
    }

    @DeleteMapping("/{name}")
    public ResponseEntity<String> deleteProduct(@PathVariable String name) {
        return ResponseEntity.ok(productService.deleteProduct(name));
    }
}
