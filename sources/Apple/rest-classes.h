#import <Foundation/Foundation.h>

@protocol RestQueryDelegate <NSObject>
- queryDidComplete: (NSData *) data: (NSURLResponse *) response: (NSError *) error;
@end

@protocol RestRequestProvider <NSObject>
- make: (NSURL *) url;
@end

@interface RestBaseController : NSObject
@property (nullable) id<RestQueryDelegate> delegate;

- (id)init;
- fetch:(NSString *)string :(id<RestRequestProvider>)provider;
@end