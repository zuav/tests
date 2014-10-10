#import <stdio.h>
#import <objc/NXConstStr.h>
//#import <Foundation/Foundation.h>

int main()
{
    id s = @"Hello, World!";
    //NSLog(@"%@", s);
    printf("%s\n", [s cString]);

    return 0;
}
