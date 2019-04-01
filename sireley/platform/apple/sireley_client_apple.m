#import <Foundation/Foundation.h>
#import "sireley_request_apple.h"
#import "sireley_client.h"

void SRL_submit(struct SRL_Request *request, SRL_Submit_Callback callback) {
  NSMutableURLRequest *req = request->private_->request_;
  NSURLSession *shared = [NSURLSession sharedSession];
  NSURLSessionDataTask *task = [shared dataTaskWithRequest:req completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
    callback(0);
  }];
  [task resume];
}