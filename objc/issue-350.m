#import <Object.h>
#import <NXConstStr.h>

//@interface Foo : BaseObject {
@interface Foo : Object {
    BOOL boolProperty;
    id stringProperty;
}

@property (assign) BOOL boolProperty;
@property (copy) id stringProperty;

-(id) init;
-(void) bar;

@end

@implementation Foo

@synthesize boolProperty;
@synthesize stringProperty;

- (id) init
{
    self.boolProperty = NO;
    self.stringProperty = @"";
}

- (void) bar
{
    self.boolProperty = YES;
    self.stringProperty = @"Bar";
}

@end

int main()
{
    Foo *f = [[Foo alloc] init];
    //Foo *f = [Foo alloc];

    return 0;
}
