//
//  UnitTest_12_9.m
//  UnitTest_12_9
//
//  Created by USER on 18.05.2023.
//

#import "Header.h"
#import <XCTest/XCTest.h>

@interface UnitTest_12_9 : XCTestCase

@end

@implementation UnitTest_12_9

- (void)testExample {
    
    Node* root = nullptr;
    
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);
    
    XCTAssert(search(root, 4) == true);
    XCTAssert(search(root, 2) == true);
    XCTAssert(search(root, 6) == true);
    XCTAssert(search(root, 1) == true);
    XCTAssert(search(root, 3) == true);
    XCTAssert(search(root, 5) == true);
    XCTAssert(search(root, 7) == true);
    
    XCTAssert(search(root, 0) == false);
    XCTAssert(search(root, 8) == false);
    XCTAssert(search(root, 9) == false);
    
}



@end
