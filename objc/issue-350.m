#import <objc/Object.h>
#import <objc/NXConstStr.h>

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)
@interface BaseObject : Object

+ (id)alloc;
- (void)free;

@end

@implementation BaseObject

+ (id)alloc
{
    return class_createInstance(self, 0);
}

- (void)free
{
    object_dispose(self);
}

@end /* BaseObject */

#else

typedef Object BaseObject;

#endif


@interface Foo : Object
{
    BOOL boolProperty;
    NXConstantString *stringProperty;
}

@property BOOL boolProperty;
@property (copy) NXConstantString *stringProperty;

- (id)init;
- (void)test;

@end


@implementation Foo

@synthesize boolProperty;
@synthesize stringProperty;

- (id)init
{
    if (self) {
        self.boolProperty = NO;
        self.stringProperty = @"";
    }

    return self;
}

- (void)test
{
    self.boolProperty = YES;
    self.stringProperty = @"Bar";
}

@end


int main()
{
    Foo *f = [[Foo alloc] init];
    [f test];

    return 0;
}
