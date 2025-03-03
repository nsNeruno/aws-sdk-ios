//
// Copyright 2010-2023 Amazon.com, Inc. or its affiliates. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License").
// You may not use this file except in compliance with the License.
// A copy of the License is located at
//
// http://aws.amazon.com/apache2.0
//
// or in the "license" file accompanying this file. This file is distributed
// on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import <Foundation/Foundation.h>
#import <AWSCore/AWSCore.h>
#import "AWSDynamoDBModel.h"
#import "AWSDynamoDBResources.h"

NS_ASSUME_NONNULL_BEGIN

//! SDK version for AWSDynamoDB
FOUNDATION_EXPORT NSString *const AWSDynamoDBSDKVersion;

/**
 <fullname>Amazon DynamoDB</fullname><p>Amazon DynamoDB is a fully managed NoSQL database service that provides fast and predictable performance with seamless scalability. DynamoDB lets you offload the administrative burdens of operating and scaling a distributed database, so that you don't have to worry about hardware provisioning, setup and configuration, replication, software patching, or cluster scaling.</p><p>With DynamoDB, you can create database tables that can store and retrieve any amount of data, and serve any level of request traffic. You can scale up or scale down your tables' throughput capacity without downtime or performance degradation, and use the Amazon Web Services Management Console to monitor resource utilization and performance metrics.</p><p>DynamoDB automatically spreads the data and traffic for your tables over a sufficient number of servers to handle your throughput and storage requirements, while maintaining consistent and fast performance. All of your data is stored on solid state disks (SSDs) and automatically replicated across multiple Availability Zones in an Amazon Web Services Region, providing built-in high availability and data durability.</p>
 */
@interface AWSDynamoDB : AWSService

/**
 The service configuration used to instantiate this service client.
 
 @warning Once the client is instantiated, do not modify the configuration object. It may cause unspecified behaviors.
 */
@property (nonatomic, strong, readonly) AWSServiceConfiguration *configuration;

/**
 Returns the singleton service client. If the singleton object does not exist, the SDK instantiates the default service client with `defaultServiceConfiguration` from `[AWSServiceManager defaultServiceManager]`. The reference to this object is maintained by the SDK, and you do not need to retain it manually.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`
 
 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = AWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USEast1, credentialsProvider: credentialProvider)
        AWSServiceManager.default().defaultServiceConfiguration = configuration
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
          AWSCognitoCredentialsProvider *credentialsProvider = [[AWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                          identityPoolId:@"YourIdentityPoolId"];
          AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSEast1
                                                                               credentialsProvider:credentialsProvider];
          [AWSServiceManager defaultServiceManager].defaultServiceConfiguration = configuration;

          return YES;
      }

 Then call the following to get the default service client:

 *Swift*

     let DynamoDB = AWSDynamoDB.default()

 *Objective-C*

     AWSDynamoDB *DynamoDB = [AWSDynamoDB defaultDynamoDB];

 @return The default service client.
 */
+ (instancetype)defaultDynamoDB;

/**
 Creates a service client with the given service configuration and registers it for the key.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = AWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
        AWSDynamoDB.register(with: configuration!, forKey: "USWest2DynamoDB")
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         AWSCognitoCredentialsProvider *credentialsProvider = [[AWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [AWSDynamoDB registerDynamoDBWithConfiguration:configuration forKey:@"USWest2DynamoDB"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let DynamoDB = AWSDynamoDB(forKey: "USWest2DynamoDB")

 *Objective-C*

     AWSDynamoDB *DynamoDB = [AWSDynamoDB DynamoDBForKey:@"USWest2DynamoDB"];

 @warning After calling this method, do not modify the configuration object. It may cause unspecified behaviors.

 @param configuration A service configuration object.
 @param key           A string to identify the service client.
 */
+ (void)registerDynamoDBWithConfiguration:(AWSServiceConfiguration *)configuration forKey:(NSString *)key;

/**
 Retrieves the service client associated with the key. You need to call `+ registerDynamoDBWithConfiguration:forKey:` before invoking this method.

 For example, set the default service configuration in `- application:didFinishLaunchingWithOptions:`

 *Swift*

     func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        let credentialProvider = AWSCognitoCredentialsProvider(regionType: .USEast1, identityPoolId: "YourIdentityPoolId")
        let configuration = AWSServiceConfiguration(region: .USWest2, credentialsProvider: credentialProvider)
        AWSDynamoDB.register(with: configuration!, forKey: "USWest2DynamoDB")
 
        return true
    }

 *Objective-C*

     - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
         AWSCognitoCredentialsProvider *credentialsProvider = [[AWSCognitoCredentialsProvider alloc] initWithRegionType:AWSRegionUSEast1
                                                                                                         identityPoolId:@"YourIdentityPoolId"];
         AWSServiceConfiguration *configuration = [[AWSServiceConfiguration alloc] initWithRegion:AWSRegionUSWest2
                                                                              credentialsProvider:credentialsProvider];

         [AWSDynamoDB registerDynamoDBWithConfiguration:configuration forKey:@"USWest2DynamoDB"];

         return YES;
     }

 Then call the following to get the service client:

 *Swift*

     let DynamoDB = AWSDynamoDB(forKey: "USWest2DynamoDB")

 *Objective-C*

     AWSDynamoDB *DynamoDB = [AWSDynamoDB DynamoDBForKey:@"USWest2DynamoDB"];

 @param key A string to identify the service client.

 @return An instance of the service client.
 */
+ (instancetype)DynamoDBForKey:(NSString *)key;

/**
 Removes the service client associated with the key and release it.
 
 @warning Before calling this method, make sure no method is running on this client.
 
 @param key A string to identify the service client.
 */
+ (void)removeDynamoDBForKey:(NSString *)key;

/**
 <p>This operation allows you to perform batch reads or writes on data stored in DynamoDB, using PartiQL. Each read statement in a <code>BatchExecuteStatement</code> must specify an equality condition on all key attributes. This enforces that each <code>SELECT</code> statement in a batch returns at most a single item.</p><note><p>The entire batch must consist of either read statements or write statements, you cannot mix both in one batch.</p></note><important><p>A HTTP 200 response does not mean that all statements in the BatchExecuteStatement succeeded. Error details for individual statements can be found under the <a href="https://docs.aws.amazon.com/amazondynamodb/latest/APIReference/API_BatchStatementResponse.html#DDB-Type-BatchStatementResponse-Error">Error</a> field of the <code>BatchStatementResponse</code> for each statement.</p></important>
 
 @param request A container for the necessary parameters to execute the BatchExecuteStatement service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBBatchExecuteStatementOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBBatchExecuteStatementInput
 @see AWSDynamoDBBatchExecuteStatementOutput
 */
- (AWSTask<AWSDynamoDBBatchExecuteStatementOutput *> *)batchExecuteStatement:(AWSDynamoDBBatchExecuteStatementInput *)request;

/**
 <p>This operation allows you to perform batch reads or writes on data stored in DynamoDB, using PartiQL. Each read statement in a <code>BatchExecuteStatement</code> must specify an equality condition on all key attributes. This enforces that each <code>SELECT</code> statement in a batch returns at most a single item.</p><note><p>The entire batch must consist of either read statements or write statements, you cannot mix both in one batch.</p></note><important><p>A HTTP 200 response does not mean that all statements in the BatchExecuteStatement succeeded. Error details for individual statements can be found under the <a href="https://docs.aws.amazon.com/amazondynamodb/latest/APIReference/API_BatchStatementResponse.html#DDB-Type-BatchStatementResponse-Error">Error</a> field of the <code>BatchStatementResponse</code> for each statement.</p></important>
 
 @param request A container for the necessary parameters to execute the BatchExecuteStatement service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBBatchExecuteStatementInput
 @see AWSDynamoDBBatchExecuteStatementOutput
 */
- (void)batchExecuteStatement:(AWSDynamoDBBatchExecuteStatementInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBBatchExecuteStatementOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>BatchGetItem</code> operation returns the attributes of one or more items from one or more tables. You identify requested items by primary key.</p><p>A single operation can retrieve up to 16 MB of data, which can contain as many as 100 items. <code>BatchGetItem</code> returns a partial result if the response size limit is exceeded, the table's provisioned throughput is exceeded, more than 1MB per partition is requested, or an internal processing failure occurs. If a partial result is returned, the operation returns a value for <code>UnprocessedKeys</code>. You can use this value to retry the operation starting with the next item to get.</p><important><p>If you request more than 100 items, <code>BatchGetItem</code> returns a <code>ValidationException</code> with the message "Too many items requested for the BatchGetItem call."</p></important><p>For example, if you ask to retrieve 100 items, but each individual item is 300 KB in size, the system returns 52 items (so as not to exceed the 16 MB limit). It also returns an appropriate <code>UnprocessedKeys</code> value so you can get the next page of results. If desired, your application can include its own logic to assemble the pages of results into one dataset.</p><p>If <i>none</i> of the items can be processed due to insufficient provisioned throughput on all of the tables in the request, then <code>BatchGetItem</code> returns a <code>ProvisionedThroughputExceededException</code>. If <i>at least one</i> of the items is successfully processed, then <code>BatchGetItem</code> completes successfully, while returning the keys of the unread items in <code>UnprocessedKeys</code>.</p><important><p>If DynamoDB returns any unprocessed items, you should retry the batch operation on those items. However, <i>we strongly recommend that you use an exponential backoff algorithm</i>. If you retry the batch operation immediately, the underlying read or write requests can still fail due to throttling on the individual tables. If you delay the batch operation using exponential backoff, the individual requests in the batch are much more likely to succeed.</p><p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ErrorHandling.html#BatchOperations">Batch Operations and Error Handling</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p></important><p>By default, <code>BatchGetItem</code> performs eventually consistent reads on every table in the request. If you want strongly consistent reads instead, you can set <code>ConsistentRead</code> to <code>true</code> for any or all tables.</p><p>In order to minimize response latency, <code>BatchGetItem</code> may retrieve items in parallel.</p><p>When designing your application, keep in mind that DynamoDB does not return items in any particular order. To help parse the response by item, include the primary key values for the items in your request in the <code>ProjectionExpression</code> parameter.</p><p>If a requested item does not exist, it is not returned in the result. Requests for nonexistent items consume the minimum read capacity units according to the type of read. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#CapacityUnitCalculations">Working with Tables</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the BatchGetItem service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBBatchGetItemOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBBatchGetItemInput
 @see AWSDynamoDBBatchGetItemOutput
 */
- (AWSTask<AWSDynamoDBBatchGetItemOutput *> *)batchGetItem:(AWSDynamoDBBatchGetItemInput *)request;

/**
 <p>The <code>BatchGetItem</code> operation returns the attributes of one or more items from one or more tables. You identify requested items by primary key.</p><p>A single operation can retrieve up to 16 MB of data, which can contain as many as 100 items. <code>BatchGetItem</code> returns a partial result if the response size limit is exceeded, the table's provisioned throughput is exceeded, more than 1MB per partition is requested, or an internal processing failure occurs. If a partial result is returned, the operation returns a value for <code>UnprocessedKeys</code>. You can use this value to retry the operation starting with the next item to get.</p><important><p>If you request more than 100 items, <code>BatchGetItem</code> returns a <code>ValidationException</code> with the message "Too many items requested for the BatchGetItem call."</p></important><p>For example, if you ask to retrieve 100 items, but each individual item is 300 KB in size, the system returns 52 items (so as not to exceed the 16 MB limit). It also returns an appropriate <code>UnprocessedKeys</code> value so you can get the next page of results. If desired, your application can include its own logic to assemble the pages of results into one dataset.</p><p>If <i>none</i> of the items can be processed due to insufficient provisioned throughput on all of the tables in the request, then <code>BatchGetItem</code> returns a <code>ProvisionedThroughputExceededException</code>. If <i>at least one</i> of the items is successfully processed, then <code>BatchGetItem</code> completes successfully, while returning the keys of the unread items in <code>UnprocessedKeys</code>.</p><important><p>If DynamoDB returns any unprocessed items, you should retry the batch operation on those items. However, <i>we strongly recommend that you use an exponential backoff algorithm</i>. If you retry the batch operation immediately, the underlying read or write requests can still fail due to throttling on the individual tables. If you delay the batch operation using exponential backoff, the individual requests in the batch are much more likely to succeed.</p><p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ErrorHandling.html#BatchOperations">Batch Operations and Error Handling</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p></important><p>By default, <code>BatchGetItem</code> performs eventually consistent reads on every table in the request. If you want strongly consistent reads instead, you can set <code>ConsistentRead</code> to <code>true</code> for any or all tables.</p><p>In order to minimize response latency, <code>BatchGetItem</code> may retrieve items in parallel.</p><p>When designing your application, keep in mind that DynamoDB does not return items in any particular order. To help parse the response by item, include the primary key values for the items in your request in the <code>ProjectionExpression</code> parameter.</p><p>If a requested item does not exist, it is not returned in the result. Requests for nonexistent items consume the minimum read capacity units according to the type of read. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#CapacityUnitCalculations">Working with Tables</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the BatchGetItem service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBBatchGetItemInput
 @see AWSDynamoDBBatchGetItemOutput
 */
- (void)batchGetItem:(AWSDynamoDBBatchGetItemInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBBatchGetItemOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>BatchWriteItem</code> operation puts or deletes multiple items in one or more tables. A single call to <code>BatchWriteItem</code> can transmit up to 16MB of data over the network, consisting of up to 25 item put or delete operations. While individual items can be up to 400 KB once stored, it's important to note that an item's representation might be greater than 400KB while being sent in DynamoDB's JSON format for the API call. For more details on this distinction, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/HowItWorks.NamingRulesDataTypes.html">Naming Rules and Data Types</a>.</p><note><p><code>BatchWriteItem</code> cannot update items. If you perform a <code>BatchWriteItem</code> operation on an existing item, that item's values will be overwritten by the operation and it will appear like it was updated. To update items, we recommend you use the <code>UpdateItem</code> action.</p></note><p>The individual <code>PutItem</code> and <code>DeleteItem</code> operations specified in <code>BatchWriteItem</code> are atomic; however <code>BatchWriteItem</code> as a whole is not. If any requested operations fail because the table's provisioned throughput is exceeded or an internal processing failure occurs, the failed operations are returned in the <code>UnprocessedItems</code> response parameter. You can investigate and optionally resend the requests. Typically, you would call <code>BatchWriteItem</code> in a loop. Each iteration would check for unprocessed items and submit a new <code>BatchWriteItem</code> request with those unprocessed items until all items have been processed.</p><p>If <i>none</i> of the items can be processed due to insufficient provisioned throughput on all of the tables in the request, then <code>BatchWriteItem</code> returns a <code>ProvisionedThroughputExceededException</code>.</p><important><p>If DynamoDB returns any unprocessed items, you should retry the batch operation on those items. However, <i>we strongly recommend that you use an exponential backoff algorithm</i>. If you retry the batch operation immediately, the underlying read or write requests can still fail due to throttling on the individual tables. If you delay the batch operation using exponential backoff, the individual requests in the batch are much more likely to succeed.</p><p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ErrorHandling.html#Programming.Errors.BatchOperations">Batch Operations and Error Handling</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p></important><p>With <code>BatchWriteItem</code>, you can efficiently write or delete large amounts of data, such as from Amazon EMR, or copy data from another database into DynamoDB. In order to improve performance with these large-scale operations, <code>BatchWriteItem</code> does not behave in the same way as individual <code>PutItem</code> and <code>DeleteItem</code> calls would. For example, you cannot specify conditions on individual put and delete requests, and <code>BatchWriteItem</code> does not return deleted items in the response.</p><p>If you use a programming language that supports concurrency, you can use threads to write items in parallel. Your application must include the necessary logic to manage the threads. With languages that don't support threading, you must update or delete the specified items one at a time. In both situations, <code>BatchWriteItem</code> performs the specified put and delete operations in parallel, giving you the power of the thread pool approach without having to introduce complexity into your application.</p><p>Parallel processing reduces latency, but each specified put and delete request consumes the same number of write capacity units whether it is processed in parallel or not. Delete operations on nonexistent items consume one write capacity unit.</p><p>If one or more of the following is true, DynamoDB rejects the entire batch write operation:</p><ul><li><p>One or more tables specified in the <code>BatchWriteItem</code> request does not exist.</p></li><li><p>Primary key attributes specified on an item in the request do not match those in the corresponding table's primary key schema.</p></li><li><p>You try to perform multiple operations on the same item in the same <code>BatchWriteItem</code> request. For example, you cannot put and delete the same item in the same <code>BatchWriteItem</code> request. </p></li><li><p> Your request contains at least two items with identical hash and range keys (which essentially is two put operations). </p></li><li><p>There are more than 25 requests in the batch.</p></li><li><p>Any individual item in a batch exceeds 400 KB.</p></li><li><p>The total request size exceeds 16 MB.</p></li></ul>
 
 @param request A container for the necessary parameters to execute the BatchWriteItem service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBBatchWriteItemOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBBatchWriteItemInput
 @see AWSDynamoDBBatchWriteItemOutput
 */
- (AWSTask<AWSDynamoDBBatchWriteItemOutput *> *)batchWriteItem:(AWSDynamoDBBatchWriteItemInput *)request;

/**
 <p>The <code>BatchWriteItem</code> operation puts or deletes multiple items in one or more tables. A single call to <code>BatchWriteItem</code> can transmit up to 16MB of data over the network, consisting of up to 25 item put or delete operations. While individual items can be up to 400 KB once stored, it's important to note that an item's representation might be greater than 400KB while being sent in DynamoDB's JSON format for the API call. For more details on this distinction, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/HowItWorks.NamingRulesDataTypes.html">Naming Rules and Data Types</a>.</p><note><p><code>BatchWriteItem</code> cannot update items. If you perform a <code>BatchWriteItem</code> operation on an existing item, that item's values will be overwritten by the operation and it will appear like it was updated. To update items, we recommend you use the <code>UpdateItem</code> action.</p></note><p>The individual <code>PutItem</code> and <code>DeleteItem</code> operations specified in <code>BatchWriteItem</code> are atomic; however <code>BatchWriteItem</code> as a whole is not. If any requested operations fail because the table's provisioned throughput is exceeded or an internal processing failure occurs, the failed operations are returned in the <code>UnprocessedItems</code> response parameter. You can investigate and optionally resend the requests. Typically, you would call <code>BatchWriteItem</code> in a loop. Each iteration would check for unprocessed items and submit a new <code>BatchWriteItem</code> request with those unprocessed items until all items have been processed.</p><p>If <i>none</i> of the items can be processed due to insufficient provisioned throughput on all of the tables in the request, then <code>BatchWriteItem</code> returns a <code>ProvisionedThroughputExceededException</code>.</p><important><p>If DynamoDB returns any unprocessed items, you should retry the batch operation on those items. However, <i>we strongly recommend that you use an exponential backoff algorithm</i>. If you retry the batch operation immediately, the underlying read or write requests can still fail due to throttling on the individual tables. If you delay the batch operation using exponential backoff, the individual requests in the batch are much more likely to succeed.</p><p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ErrorHandling.html#Programming.Errors.BatchOperations">Batch Operations and Error Handling</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p></important><p>With <code>BatchWriteItem</code>, you can efficiently write or delete large amounts of data, such as from Amazon EMR, or copy data from another database into DynamoDB. In order to improve performance with these large-scale operations, <code>BatchWriteItem</code> does not behave in the same way as individual <code>PutItem</code> and <code>DeleteItem</code> calls would. For example, you cannot specify conditions on individual put and delete requests, and <code>BatchWriteItem</code> does not return deleted items in the response.</p><p>If you use a programming language that supports concurrency, you can use threads to write items in parallel. Your application must include the necessary logic to manage the threads. With languages that don't support threading, you must update or delete the specified items one at a time. In both situations, <code>BatchWriteItem</code> performs the specified put and delete operations in parallel, giving you the power of the thread pool approach without having to introduce complexity into your application.</p><p>Parallel processing reduces latency, but each specified put and delete request consumes the same number of write capacity units whether it is processed in parallel or not. Delete operations on nonexistent items consume one write capacity unit.</p><p>If one or more of the following is true, DynamoDB rejects the entire batch write operation:</p><ul><li><p>One or more tables specified in the <code>BatchWriteItem</code> request does not exist.</p></li><li><p>Primary key attributes specified on an item in the request do not match those in the corresponding table's primary key schema.</p></li><li><p>You try to perform multiple operations on the same item in the same <code>BatchWriteItem</code> request. For example, you cannot put and delete the same item in the same <code>BatchWriteItem</code> request. </p></li><li><p> Your request contains at least two items with identical hash and range keys (which essentially is two put operations). </p></li><li><p>There are more than 25 requests in the batch.</p></li><li><p>Any individual item in a batch exceeds 400 KB.</p></li><li><p>The total request size exceeds 16 MB.</p></li></ul>
 
 @param request A container for the necessary parameters to execute the BatchWriteItem service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBBatchWriteItemInput
 @see AWSDynamoDBBatchWriteItemOutput
 */
- (void)batchWriteItem:(AWSDynamoDBBatchWriteItemInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBBatchWriteItemOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a backup for an existing table.</p><p> Each time you create an on-demand backup, the entire table data is backed up. There is no limit to the number of on-demand backups that can be taken. </p><p> When you create an on-demand backup, a time marker of the request is cataloged, and the backup is created asynchronously, by applying all changes until the time of the request to the last full table snapshot. Backup requests are processed instantaneously and become available for restore within minutes. </p><p>You can call <code>CreateBackup</code> at a maximum rate of 50 times per second.</p><p>All backups in DynamoDB work without consuming any provisioned throughput on the table.</p><p> If you submit a backup request on 2018-12-14 at 14:25:00, the backup is guaranteed to contain all data committed to the table up to 14:24:00, and data committed after 14:26:00 will not be. The backup might contain data modifications made between 14:24:00 and 14:26:00. On-demand backup does not support causal consistency. </p><p> Along with data, the following are also included on the backups: </p><ul><li><p>Global secondary indexes (GSIs)</p></li><li><p>Local secondary indexes (LSIs)</p></li><li><p>Streams</p></li><li><p>Provisioned read and write capacity</p></li></ul>
 
 @param request A container for the necessary parameters to execute the CreateBackup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBCreateBackupOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorTableInUse`, `AWSDynamoDBErrorContinuousBackupsUnavailable`, `AWSDynamoDBErrorBackupInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBCreateBackupInput
 @see AWSDynamoDBCreateBackupOutput
 */
- (AWSTask<AWSDynamoDBCreateBackupOutput *> *)createBackup:(AWSDynamoDBCreateBackupInput *)request;

/**
 <p>Creates a backup for an existing table.</p><p> Each time you create an on-demand backup, the entire table data is backed up. There is no limit to the number of on-demand backups that can be taken. </p><p> When you create an on-demand backup, a time marker of the request is cataloged, and the backup is created asynchronously, by applying all changes until the time of the request to the last full table snapshot. Backup requests are processed instantaneously and become available for restore within minutes. </p><p>You can call <code>CreateBackup</code> at a maximum rate of 50 times per second.</p><p>All backups in DynamoDB work without consuming any provisioned throughput on the table.</p><p> If you submit a backup request on 2018-12-14 at 14:25:00, the backup is guaranteed to contain all data committed to the table up to 14:24:00, and data committed after 14:26:00 will not be. The backup might contain data modifications made between 14:24:00 and 14:26:00. On-demand backup does not support causal consistency. </p><p> Along with data, the following are also included on the backups: </p><ul><li><p>Global secondary indexes (GSIs)</p></li><li><p>Local secondary indexes (LSIs)</p></li><li><p>Streams</p></li><li><p>Provisioned read and write capacity</p></li></ul>
 
 @param request A container for the necessary parameters to execute the CreateBackup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorTableInUse`, `AWSDynamoDBErrorContinuousBackupsUnavailable`, `AWSDynamoDBErrorBackupInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBCreateBackupInput
 @see AWSDynamoDBCreateBackupOutput
 */
- (void)createBackup:(AWSDynamoDBCreateBackupInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBCreateBackupOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a global table from an existing table. A global table creates a replication relationship between two or more DynamoDB tables with the same table name in the provided Regions. </p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important><p>If you want to add a new replica table to a global table, each of the following conditions must be true:</p><ul><li><p>The table must have the same primary key as all of the other replicas.</p></li><li><p>The table must have the same name as all of the other replicas.</p></li><li><p>The table must have DynamoDB Streams enabled, with the stream containing both the new and the old images of the item.</p></li><li><p>None of the replica tables in the global table can contain any data.</p></li></ul><p> If global secondary indexes are specified, then the following conditions must also be met: </p><ul><li><p> The global secondary indexes must have the same name. </p></li><li><p> The global secondary indexes must have the same hash key and sort key (if present). </p></li></ul><p> If local secondary indexes are specified, then the following conditions must also be met: </p><ul><li><p> The local secondary indexes must have the same name. </p></li><li><p> The local secondary indexes must have the same hash key and sort key (if present). </p></li></ul><important><p> Write capacity settings should be set consistently across your replica tables and secondary indexes. DynamoDB strongly recommends enabling auto scaling to manage the write capacity settings for all of your global tables replicas and indexes. </p><p> If you prefer to manage write capacity settings manually, you should provision equal replicated write capacity units to your replica tables. You should also provision equal replicated write capacity units to matching secondary indexes across your global table. </p></important>
 
 @param request A container for the necessary parameters to execute the CreateGlobalTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBCreateGlobalTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorGlobalTableAlreadyExists`, `AWSDynamoDBErrorTableNotFound`.
 
 @see AWSDynamoDBCreateGlobalTableInput
 @see AWSDynamoDBCreateGlobalTableOutput
 */
- (AWSTask<AWSDynamoDBCreateGlobalTableOutput *> *)createGlobalTable:(AWSDynamoDBCreateGlobalTableInput *)request;

/**
 <p>Creates a global table from an existing table. A global table creates a replication relationship between two or more DynamoDB tables with the same table name in the provided Regions. </p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important><p>If you want to add a new replica table to a global table, each of the following conditions must be true:</p><ul><li><p>The table must have the same primary key as all of the other replicas.</p></li><li><p>The table must have the same name as all of the other replicas.</p></li><li><p>The table must have DynamoDB Streams enabled, with the stream containing both the new and the old images of the item.</p></li><li><p>None of the replica tables in the global table can contain any data.</p></li></ul><p> If global secondary indexes are specified, then the following conditions must also be met: </p><ul><li><p> The global secondary indexes must have the same name. </p></li><li><p> The global secondary indexes must have the same hash key and sort key (if present). </p></li></ul><p> If local secondary indexes are specified, then the following conditions must also be met: </p><ul><li><p> The local secondary indexes must have the same name. </p></li><li><p> The local secondary indexes must have the same hash key and sort key (if present). </p></li></ul><important><p> Write capacity settings should be set consistently across your replica tables and secondary indexes. DynamoDB strongly recommends enabling auto scaling to manage the write capacity settings for all of your global tables replicas and indexes. </p><p> If you prefer to manage write capacity settings manually, you should provision equal replicated write capacity units to your replica tables. You should also provision equal replicated write capacity units to matching secondary indexes across your global table. </p></important>
 
 @param request A container for the necessary parameters to execute the CreateGlobalTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorGlobalTableAlreadyExists`, `AWSDynamoDBErrorTableNotFound`.
 
 @see AWSDynamoDBCreateGlobalTableInput
 @see AWSDynamoDBCreateGlobalTableOutput
 */
- (void)createGlobalTable:(AWSDynamoDBCreateGlobalTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBCreateGlobalTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>CreateTable</code> operation adds a new table to your account. In an Amazon Web Services account, table names must be unique within each Region. That is, you can have two tables with same name if you create the tables in different Regions.</p><p><code>CreateTable</code> is an asynchronous operation. Upon receiving a <code>CreateTable</code> request, DynamoDB immediately returns a response with a <code>TableStatus</code> of <code>CREATING</code>. After the table is created, DynamoDB sets the <code>TableStatus</code> to <code>ACTIVE</code>. You can perform read and write operations only on an <code>ACTIVE</code> table. </p><p>You can optionally define secondary indexes on the new table, as part of the <code>CreateTable</code> operation. If you want to create multiple tables with secondary indexes on them, you must create the tables sequentially. Only one table with secondary indexes can be in the <code>CREATING</code> state at any given time.</p><p>You can use the <code>DescribeTable</code> action to check the table status.</p>
 
 @param request A container for the necessary parameters to execute the CreateTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBCreateTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBCreateTableInput
 @see AWSDynamoDBCreateTableOutput
 */
- (AWSTask<AWSDynamoDBCreateTableOutput *> *)createTable:(AWSDynamoDBCreateTableInput *)request;

/**
 <p>The <code>CreateTable</code> operation adds a new table to your account. In an Amazon Web Services account, table names must be unique within each Region. That is, you can have two tables with same name if you create the tables in different Regions.</p><p><code>CreateTable</code> is an asynchronous operation. Upon receiving a <code>CreateTable</code> request, DynamoDB immediately returns a response with a <code>TableStatus</code> of <code>CREATING</code>. After the table is created, DynamoDB sets the <code>TableStatus</code> to <code>ACTIVE</code>. You can perform read and write operations only on an <code>ACTIVE</code> table. </p><p>You can optionally define secondary indexes on the new table, as part of the <code>CreateTable</code> operation. If you want to create multiple tables with secondary indexes on them, you must create the tables sequentially. Only one table with secondary indexes can be in the <code>CREATING</code> state at any given time.</p><p>You can use the <code>DescribeTable</code> action to check the table status.</p>
 
 @param request A container for the necessary parameters to execute the CreateTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBCreateTableInput
 @see AWSDynamoDBCreateTableOutput
 */
- (void)createTable:(AWSDynamoDBCreateTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBCreateTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes an existing backup of a table.</p><p>You can call <code>DeleteBackup</code> at a maximum rate of 10 times per second.</p>
 
 @param request A container for the necessary parameters to execute the DeleteBackup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDeleteBackupOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorBackupNotFound`, `AWSDynamoDBErrorBackupInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDeleteBackupInput
 @see AWSDynamoDBDeleteBackupOutput
 */
- (AWSTask<AWSDynamoDBDeleteBackupOutput *> *)deleteBackup:(AWSDynamoDBDeleteBackupInput *)request;

/**
 <p>Deletes an existing backup of a table.</p><p>You can call <code>DeleteBackup</code> at a maximum rate of 10 times per second.</p>
 
 @param request A container for the necessary parameters to execute the DeleteBackup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorBackupNotFound`, `AWSDynamoDBErrorBackupInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDeleteBackupInput
 @see AWSDynamoDBDeleteBackupOutput
 */
- (void)deleteBackup:(AWSDynamoDBDeleteBackupInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDeleteBackupOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Deletes a single item in a table by primary key. You can perform a conditional delete operation that deletes the item if it exists, or if it has an expected attribute value.</p><p>In addition to deleting an item, you can also return the item's attribute values in the same operation, using the <code>ReturnValues</code> parameter.</p><p>Unless you specify conditions, the <code>DeleteItem</code> is an idempotent operation; running it multiple times on the same item or attribute does <i>not</i> result in an error response.</p><p>Conditional deletes are useful for deleting items only if specific conditions are met. If those conditions are met, DynamoDB performs the delete. Otherwise, the item is not deleted.</p>
 
 @param request A container for the necessary parameters to execute the DeleteItem service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDeleteItemOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDeleteItemInput
 @see AWSDynamoDBDeleteItemOutput
 */
- (AWSTask<AWSDynamoDBDeleteItemOutput *> *)deleteItem:(AWSDynamoDBDeleteItemInput *)request;

/**
 <p>Deletes a single item in a table by primary key. You can perform a conditional delete operation that deletes the item if it exists, or if it has an expected attribute value.</p><p>In addition to deleting an item, you can also return the item's attribute values in the same operation, using the <code>ReturnValues</code> parameter.</p><p>Unless you specify conditions, the <code>DeleteItem</code> is an idempotent operation; running it multiple times on the same item or attribute does <i>not</i> result in an error response.</p><p>Conditional deletes are useful for deleting items only if specific conditions are met. If those conditions are met, DynamoDB performs the delete. Otherwise, the item is not deleted.</p>
 
 @param request A container for the necessary parameters to execute the DeleteItem service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDeleteItemInput
 @see AWSDynamoDBDeleteItemOutput
 */
- (void)deleteItem:(AWSDynamoDBDeleteItemInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDeleteItemOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>DeleteTable</code> operation deletes a table and all of its items. After a <code>DeleteTable</code> request, the specified table is in the <code>DELETING</code> state until DynamoDB completes the deletion. If the table is in the <code>ACTIVE</code> state, you can delete it. If a table is in <code>CREATING</code> or <code>UPDATING</code> states, then DynamoDB returns a <code>ResourceInUseException</code>. If the specified table does not exist, DynamoDB returns a <code>ResourceNotFoundException</code>. If table is already in the <code>DELETING</code> state, no error is returned. </p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important><note><p>DynamoDB might continue to accept data read and write operations, such as <code>GetItem</code> and <code>PutItem</code>, on a table in the <code>DELETING</code> state until the table deletion is complete.</p></note><p>When you delete a table, any indexes on that table are also deleted.</p><p>If you have DynamoDB Streams enabled on the table, then the corresponding stream on that table goes into the <code>DISABLED</code> state, and the stream is automatically deleted after 24 hours.</p><p>Use the <code>DescribeTable</code> action to check the status of the table. </p>
 
 @param request A container for the necessary parameters to execute the DeleteTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDeleteTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDeleteTableInput
 @see AWSDynamoDBDeleteTableOutput
 */
- (AWSTask<AWSDynamoDBDeleteTableOutput *> *)deleteTable:(AWSDynamoDBDeleteTableInput *)request;

/**
 <p>The <code>DeleteTable</code> operation deletes a table and all of its items. After a <code>DeleteTable</code> request, the specified table is in the <code>DELETING</code> state until DynamoDB completes the deletion. If the table is in the <code>ACTIVE</code> state, you can delete it. If a table is in <code>CREATING</code> or <code>UPDATING</code> states, then DynamoDB returns a <code>ResourceInUseException</code>. If the specified table does not exist, DynamoDB returns a <code>ResourceNotFoundException</code>. If table is already in the <code>DELETING</code> state, no error is returned. </p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important><note><p>DynamoDB might continue to accept data read and write operations, such as <code>GetItem</code> and <code>PutItem</code>, on a table in the <code>DELETING</code> state until the table deletion is complete.</p></note><p>When you delete a table, any indexes on that table are also deleted.</p><p>If you have DynamoDB Streams enabled on the table, then the corresponding stream on that table goes into the <code>DISABLED</code> state, and the stream is automatically deleted after 24 hours.</p><p>Use the <code>DescribeTable</code> action to check the status of the table. </p>
 
 @param request A container for the necessary parameters to execute the DeleteTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDeleteTableInput
 @see AWSDynamoDBDeleteTableOutput
 */
- (void)deleteTable:(AWSDynamoDBDeleteTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDeleteTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes an existing backup of a table.</p><p>You can call <code>DescribeBackup</code> at a maximum rate of 10 times per second.</p>
 
 @param request A container for the necessary parameters to execute the DescribeBackup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeBackupOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorBackupNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeBackupInput
 @see AWSDynamoDBDescribeBackupOutput
 */
- (AWSTask<AWSDynamoDBDescribeBackupOutput *> *)describeBackup:(AWSDynamoDBDescribeBackupInput *)request;

/**
 <p>Describes an existing backup of a table.</p><p>You can call <code>DescribeBackup</code> at a maximum rate of 10 times per second.</p>
 
 @param request A container for the necessary parameters to execute the DescribeBackup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorBackupNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeBackupInput
 @see AWSDynamoDBDescribeBackupOutput
 */
- (void)describeBackup:(AWSDynamoDBDescribeBackupInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeBackupOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Checks the status of continuous backups and point in time recovery on the specified table. Continuous backups are <code>ENABLED</code> on all tables at table creation. If point in time recovery is enabled, <code>PointInTimeRecoveryStatus</code> will be set to ENABLED.</p><p> After continuous backups and point in time recovery are enabled, you can restore to any point in time within <code>EarliestRestorableDateTime</code> and <code>LatestRestorableDateTime</code>. </p><p><code>LatestRestorableDateTime</code> is typically 5 minutes before the current time. You can restore your table to any point in time during the last 35 days. </p><p>You can call <code>DescribeContinuousBackups</code> at a maximum rate of 10 times per second.</p>
 
 @param request A container for the necessary parameters to execute the DescribeContinuousBackups service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeContinuousBackupsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeContinuousBackupsInput
 @see AWSDynamoDBDescribeContinuousBackupsOutput
 */
- (AWSTask<AWSDynamoDBDescribeContinuousBackupsOutput *> *)describeContinuousBackups:(AWSDynamoDBDescribeContinuousBackupsInput *)request;

/**
 <p>Checks the status of continuous backups and point in time recovery on the specified table. Continuous backups are <code>ENABLED</code> on all tables at table creation. If point in time recovery is enabled, <code>PointInTimeRecoveryStatus</code> will be set to ENABLED.</p><p> After continuous backups and point in time recovery are enabled, you can restore to any point in time within <code>EarliestRestorableDateTime</code> and <code>LatestRestorableDateTime</code>. </p><p><code>LatestRestorableDateTime</code> is typically 5 minutes before the current time. You can restore your table to any point in time during the last 35 days. </p><p>You can call <code>DescribeContinuousBackups</code> at a maximum rate of 10 times per second.</p>
 
 @param request A container for the necessary parameters to execute the DescribeContinuousBackups service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeContinuousBackupsInput
 @see AWSDynamoDBDescribeContinuousBackupsOutput
 */
- (void)describeContinuousBackups:(AWSDynamoDBDescribeContinuousBackupsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeContinuousBackupsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about contributor insights for a given table or global secondary index.</p>
 
 @param request A container for the necessary parameters to execute the DescribeContributorInsights service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeContributorInsightsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeContributorInsightsInput
 @see AWSDynamoDBDescribeContributorInsightsOutput
 */
- (AWSTask<AWSDynamoDBDescribeContributorInsightsOutput *> *)describeContributorInsights:(AWSDynamoDBDescribeContributorInsightsInput *)request;

/**
 <p>Returns information about contributor insights for a given table or global secondary index.</p>
 
 @param request A container for the necessary parameters to execute the DescribeContributorInsights service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeContributorInsightsInput
 @see AWSDynamoDBDescribeContributorInsightsOutput
 */
- (void)describeContributorInsights:(AWSDynamoDBDescribeContributorInsightsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeContributorInsightsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns the regional endpoint information. For more information on policy permissions, please see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/inter-network-traffic-privacy.html#inter-network-traffic-DescribeEndpoints">Internetwork traffic privacy</a>.</p>
 
 @param request A container for the necessary parameters to execute the DescribeEndpoints service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeEndpointsResponse`.
 
 @see AWSDynamoDBDescribeEndpointsRequest
 @see AWSDynamoDBDescribeEndpointsResponse
 */
- (AWSTask<AWSDynamoDBDescribeEndpointsResponse *> *)describeEndpoints:(AWSDynamoDBDescribeEndpointsRequest *)request;

/**
 <p>Returns the regional endpoint information. For more information on policy permissions, please see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/inter-network-traffic-privacy.html#inter-network-traffic-DescribeEndpoints">Internetwork traffic privacy</a>.</p>
 
 @param request A container for the necessary parameters to execute the DescribeEndpoints service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful.
 
 @see AWSDynamoDBDescribeEndpointsRequest
 @see AWSDynamoDBDescribeEndpointsResponse
 */
- (void)describeEndpoints:(AWSDynamoDBDescribeEndpointsRequest *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeEndpointsResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes an existing table export.</p>
 
 @param request A container for the necessary parameters to execute the DescribeExport service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeExportOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorExportNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeExportInput
 @see AWSDynamoDBDescribeExportOutput
 */
- (AWSTask<AWSDynamoDBDescribeExportOutput *> *)describeExport:(AWSDynamoDBDescribeExportInput *)request;

/**
 <p>Describes an existing table export.</p>
 
 @param request A container for the necessary parameters to execute the DescribeExport service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorExportNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeExportInput
 @see AWSDynamoDBDescribeExportOutput
 */
- (void)describeExport:(AWSDynamoDBDescribeExportInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeExportOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about the specified global table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the DescribeGlobalTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeGlobalTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorGlobalTableNotFound`.
 
 @see AWSDynamoDBDescribeGlobalTableInput
 @see AWSDynamoDBDescribeGlobalTableOutput
 */
- (AWSTask<AWSDynamoDBDescribeGlobalTableOutput *> *)describeGlobalTable:(AWSDynamoDBDescribeGlobalTableInput *)request;

/**
 <p>Returns information about the specified global table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the DescribeGlobalTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorGlobalTableNotFound`.
 
 @see AWSDynamoDBDescribeGlobalTableInput
 @see AWSDynamoDBDescribeGlobalTableOutput
 */
- (void)describeGlobalTable:(AWSDynamoDBDescribeGlobalTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeGlobalTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes Region-specific settings for a global table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the DescribeGlobalTableSettings service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeGlobalTableSettingsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorGlobalTableNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeGlobalTableSettingsInput
 @see AWSDynamoDBDescribeGlobalTableSettingsOutput
 */
- (AWSTask<AWSDynamoDBDescribeGlobalTableSettingsOutput *> *)describeGlobalTableSettings:(AWSDynamoDBDescribeGlobalTableSettingsInput *)request;

/**
 <p>Describes Region-specific settings for a global table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the DescribeGlobalTableSettings service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorGlobalTableNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeGlobalTableSettingsInput
 @see AWSDynamoDBDescribeGlobalTableSettingsOutput
 */
- (void)describeGlobalTableSettings:(AWSDynamoDBDescribeGlobalTableSettingsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeGlobalTableSettingsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Represents the properties of the import. </p>
 
 @param request A container for the necessary parameters to execute the DescribeImport service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeImportOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorImportNotFound`.
 
 @see AWSDynamoDBDescribeImportInput
 @see AWSDynamoDBDescribeImportOutput
 */
- (AWSTask<AWSDynamoDBDescribeImportOutput *> *)describeImport:(AWSDynamoDBDescribeImportInput *)request;

/**
 <p> Represents the properties of the import. </p>
 
 @param request A container for the necessary parameters to execute the DescribeImport service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorImportNotFound`.
 
 @see AWSDynamoDBDescribeImportInput
 @see AWSDynamoDBDescribeImportOutput
 */
- (void)describeImport:(AWSDynamoDBDescribeImportInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeImportOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about the status of Kinesis streaming.</p>
 
 @param request A container for the necessary parameters to execute the DescribeKinesisStreamingDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeKinesisStreamingDestinationOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeKinesisStreamingDestinationInput
 @see AWSDynamoDBDescribeKinesisStreamingDestinationOutput
 */
- (AWSTask<AWSDynamoDBDescribeKinesisStreamingDestinationOutput *> *)describeKinesisStreamingDestination:(AWSDynamoDBDescribeKinesisStreamingDestinationInput *)request;

/**
 <p>Returns information about the status of Kinesis streaming.</p>
 
 @param request A container for the necessary parameters to execute the DescribeKinesisStreamingDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeKinesisStreamingDestinationInput
 @see AWSDynamoDBDescribeKinesisStreamingDestinationOutput
 */
- (void)describeKinesisStreamingDestination:(AWSDynamoDBDescribeKinesisStreamingDestinationInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeKinesisStreamingDestinationOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns the current provisioned-capacity quotas for your Amazon Web Services account in a Region, both for the Region as a whole and for any one DynamoDB table that you create there.</p><p>When you establish an Amazon Web Services account, the account has initial quotas on the maximum read capacity units and write capacity units that you can provision across all of your DynamoDB tables in a given Region. Also, there are per-table quotas that apply when you create a table there. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Service, Account, and Table Quotas</a> page in the <i>Amazon DynamoDB Developer Guide</i>.</p><p>Although you can increase these quotas by filing a case at <a href="https://console.aws.amazon.com/support/home#/">Amazon Web Services Support Center</a>, obtaining the increase is not instantaneous. The <code>DescribeLimits</code> action lets you write code to compare the capacity you are currently using to those quotas imposed by your account so that you have enough time to apply for an increase before you hit a quota.</p><p>For example, you could use one of the Amazon Web Services SDKs to do the following:</p><ol><li><p>Call <code>DescribeLimits</code> for a particular Region to obtain your current account quotas on provisioned capacity there.</p></li><li><p>Create a variable to hold the aggregate read capacity units provisioned for all your tables in that Region, and one to hold the aggregate write capacity units. Zero them both.</p></li><li><p>Call <code>ListTables</code> to obtain a list of all your DynamoDB tables.</p></li><li><p>For each table name listed by <code>ListTables</code>, do the following:</p><ul><li><p>Call <code>DescribeTable</code> with the table name.</p></li><li><p>Use the data returned by <code>DescribeTable</code> to add the read capacity units and write capacity units provisioned for the table itself to your variables.</p></li><li><p>If the table has one or more global secondary indexes (GSIs), loop over these GSIs and add their provisioned capacity values to your variables as well.</p></li></ul></li><li><p>Report the account quotas for that Region returned by <code>DescribeLimits</code>, along with the total current provisioned capacity levels you have calculated.</p></li></ol><p>This will let you see whether you are getting close to your account-level quotas.</p><p>The per-table quotas apply only when you are creating a new table. They restrict the sum of the provisioned capacity of the new table itself and all its global secondary indexes.</p><p>For existing tables and their GSIs, DynamoDB doesn't let you increase provisioned capacity extremely rapidly, but the only quota that applies is that the aggregate provisioned capacity over all your tables and GSIs cannot exceed either of the per-account quotas.</p><note><p><code>DescribeLimits</code> should only be called periodically. You can expect throttling errors if you call it more than once in a minute.</p></note><p>The <code>DescribeLimits</code> Request element has no content.</p>
 
 @param request A container for the necessary parameters to execute the DescribeLimits service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeLimitsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeLimitsInput
 @see AWSDynamoDBDescribeLimitsOutput
 */
- (AWSTask<AWSDynamoDBDescribeLimitsOutput *> *)describeLimits:(AWSDynamoDBDescribeLimitsInput *)request;

/**
 <p>Returns the current provisioned-capacity quotas for your Amazon Web Services account in a Region, both for the Region as a whole and for any one DynamoDB table that you create there.</p><p>When you establish an Amazon Web Services account, the account has initial quotas on the maximum read capacity units and write capacity units that you can provision across all of your DynamoDB tables in a given Region. Also, there are per-table quotas that apply when you create a table there. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Service, Account, and Table Quotas</a> page in the <i>Amazon DynamoDB Developer Guide</i>.</p><p>Although you can increase these quotas by filing a case at <a href="https://console.aws.amazon.com/support/home#/">Amazon Web Services Support Center</a>, obtaining the increase is not instantaneous. The <code>DescribeLimits</code> action lets you write code to compare the capacity you are currently using to those quotas imposed by your account so that you have enough time to apply for an increase before you hit a quota.</p><p>For example, you could use one of the Amazon Web Services SDKs to do the following:</p><ol><li><p>Call <code>DescribeLimits</code> for a particular Region to obtain your current account quotas on provisioned capacity there.</p></li><li><p>Create a variable to hold the aggregate read capacity units provisioned for all your tables in that Region, and one to hold the aggregate write capacity units. Zero them both.</p></li><li><p>Call <code>ListTables</code> to obtain a list of all your DynamoDB tables.</p></li><li><p>For each table name listed by <code>ListTables</code>, do the following:</p><ul><li><p>Call <code>DescribeTable</code> with the table name.</p></li><li><p>Use the data returned by <code>DescribeTable</code> to add the read capacity units and write capacity units provisioned for the table itself to your variables.</p></li><li><p>If the table has one or more global secondary indexes (GSIs), loop over these GSIs and add their provisioned capacity values to your variables as well.</p></li></ul></li><li><p>Report the account quotas for that Region returned by <code>DescribeLimits</code>, along with the total current provisioned capacity levels you have calculated.</p></li></ol><p>This will let you see whether you are getting close to your account-level quotas.</p><p>The per-table quotas apply only when you are creating a new table. They restrict the sum of the provisioned capacity of the new table itself and all its global secondary indexes.</p><p>For existing tables and their GSIs, DynamoDB doesn't let you increase provisioned capacity extremely rapidly, but the only quota that applies is that the aggregate provisioned capacity over all your tables and GSIs cannot exceed either of the per-account quotas.</p><note><p><code>DescribeLimits</code> should only be called periodically. You can expect throttling errors if you call it more than once in a minute.</p></note><p>The <code>DescribeLimits</code> Request element has no content.</p>
 
 @param request A container for the necessary parameters to execute the DescribeLimits service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeLimitsInput
 @see AWSDynamoDBDescribeLimitsOutput
 */
- (void)describeLimits:(AWSDynamoDBDescribeLimitsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeLimitsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns information about the table, including the current status of the table, when it was created, the primary key schema, and any indexes on the table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important><note><p>If you issue a <code>DescribeTable</code> request immediately after a <code>CreateTable</code> request, DynamoDB might return a <code>ResourceNotFoundException</code>. This is because <code>DescribeTable</code> uses an eventually consistent query, and the metadata for your table might not be available at that moment. Wait for a few seconds, and then try the <code>DescribeTable</code> request again.</p></note>
 
 @param request A container for the necessary parameters to execute the DescribeTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeTableInput
 @see AWSDynamoDBDescribeTableOutput
 */
- (AWSTask<AWSDynamoDBDescribeTableOutput *> *)describeTable:(AWSDynamoDBDescribeTableInput *)request;

/**
 <p>Returns information about the table, including the current status of the table, when it was created, the primary key schema, and any indexes on the table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important><note><p>If you issue a <code>DescribeTable</code> request immediately after a <code>CreateTable</code> request, DynamoDB might return a <code>ResourceNotFoundException</code>. This is because <code>DescribeTable</code> uses an eventually consistent query, and the metadata for your table might not be available at that moment. Wait for a few seconds, and then try the <code>DescribeTable</code> request again.</p></note>
 
 @param request A container for the necessary parameters to execute the DescribeTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeTableInput
 @see AWSDynamoDBDescribeTableOutput
 */
- (void)describeTable:(AWSDynamoDBDescribeTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Describes auto scaling settings across replicas of the global table at once.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables.</p></important>
 
 @param request A container for the necessary parameters to execute the DescribeTableReplicaAutoScaling service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeTableReplicaAutoScalingOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeTableReplicaAutoScalingInput
 @see AWSDynamoDBDescribeTableReplicaAutoScalingOutput
 */
- (AWSTask<AWSDynamoDBDescribeTableReplicaAutoScalingOutput *> *)describeTableReplicaAutoScaling:(AWSDynamoDBDescribeTableReplicaAutoScalingInput *)request;

/**
 <p>Describes auto scaling settings across replicas of the global table at once.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables.</p></important>
 
 @param request A container for the necessary parameters to execute the DescribeTableReplicaAutoScaling service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeTableReplicaAutoScalingInput
 @see AWSDynamoDBDescribeTableReplicaAutoScalingOutput
 */
- (void)describeTableReplicaAutoScaling:(AWSDynamoDBDescribeTableReplicaAutoScalingInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeTableReplicaAutoScalingOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Gives a description of the Time to Live (TTL) status on the specified table. </p>
 
 @param request A container for the necessary parameters to execute the DescribeTimeToLive service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBDescribeTimeToLiveOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeTimeToLiveInput
 @see AWSDynamoDBDescribeTimeToLiveOutput
 */
- (AWSTask<AWSDynamoDBDescribeTimeToLiveOutput *> *)describeTimeToLive:(AWSDynamoDBDescribeTimeToLiveInput *)request;

/**
 <p>Gives a description of the Time to Live (TTL) status on the specified table. </p>
 
 @param request A container for the necessary parameters to execute the DescribeTimeToLive service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBDescribeTimeToLiveInput
 @see AWSDynamoDBDescribeTimeToLiveOutput
 */
- (void)describeTimeToLive:(AWSDynamoDBDescribeTimeToLiveInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBDescribeTimeToLiveOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Stops replication from the DynamoDB table to the Kinesis data stream. This is done without deleting either of the resources.</p>
 
 @param request A container for the necessary parameters to execute the DisableKinesisStreamingDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBKinesisStreamingDestinationOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`.
 
 @see AWSDynamoDBKinesisStreamingDestinationInput
 @see AWSDynamoDBKinesisStreamingDestinationOutput
 */
- (AWSTask<AWSDynamoDBKinesisStreamingDestinationOutput *> *)disableKinesisStreamingDestination:(AWSDynamoDBKinesisStreamingDestinationInput *)request;

/**
 <p>Stops replication from the DynamoDB table to the Kinesis data stream. This is done without deleting either of the resources.</p>
 
 @param request A container for the necessary parameters to execute the DisableKinesisStreamingDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`.
 
 @see AWSDynamoDBKinesisStreamingDestinationInput
 @see AWSDynamoDBKinesisStreamingDestinationOutput
 */
- (void)disableKinesisStreamingDestination:(AWSDynamoDBKinesisStreamingDestinationInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBKinesisStreamingDestinationOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Starts table data replication to the specified Kinesis data stream at a timestamp chosen during the enable workflow. If this operation doesn't return results immediately, use DescribeKinesisStreamingDestination to check if streaming to the Kinesis data stream is ACTIVE.</p>
 
 @param request A container for the necessary parameters to execute the EnableKinesisStreamingDestination service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBKinesisStreamingDestinationOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`.
 
 @see AWSDynamoDBKinesisStreamingDestinationInput
 @see AWSDynamoDBKinesisStreamingDestinationOutput
 */
- (AWSTask<AWSDynamoDBKinesisStreamingDestinationOutput *> *)enableKinesisStreamingDestination:(AWSDynamoDBKinesisStreamingDestinationInput *)request;

/**
 <p>Starts table data replication to the specified Kinesis data stream at a timestamp chosen during the enable workflow. If this operation doesn't return results immediately, use DescribeKinesisStreamingDestination to check if streaming to the Kinesis data stream is ACTIVE.</p>
 
 @param request A container for the necessary parameters to execute the EnableKinesisStreamingDestination service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`.
 
 @see AWSDynamoDBKinesisStreamingDestinationInput
 @see AWSDynamoDBKinesisStreamingDestinationOutput
 */
- (void)enableKinesisStreamingDestination:(AWSDynamoDBKinesisStreamingDestinationInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBKinesisStreamingDestinationOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>This operation allows you to perform reads and singleton writes on data stored in DynamoDB, using PartiQL.</p><p>For PartiQL reads (<code>SELECT</code> statement), if the total number of processed items exceeds the maximum dataset size limit of 1 MB, the read stops and results are returned to the user as a <code>LastEvaluatedKey</code> value to continue the read in a subsequent operation. If the filter criteria in <code>WHERE</code> clause does not match any data, the read will return an empty result set.</p><p>A single <code>SELECT</code> statement response can return up to the maximum number of items (if using the Limit parameter) or a maximum of 1 MB of data (and then apply any filtering to the results using <code>WHERE</code> clause). If <code>LastEvaluatedKey</code> is present in the response, you need to paginate the result set. If <code>NextToken</code> is present, you need to paginate the result set and include <code>NextToken</code>.</p>
 
 @param request A container for the necessary parameters to execute the ExecuteStatement service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBExecuteStatementOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorDuplicateItem`.
 
 @see AWSDynamoDBExecuteStatementInput
 @see AWSDynamoDBExecuteStatementOutput
 */
- (AWSTask<AWSDynamoDBExecuteStatementOutput *> *)executeStatement:(AWSDynamoDBExecuteStatementInput *)request;

/**
 <p>This operation allows you to perform reads and singleton writes on data stored in DynamoDB, using PartiQL.</p><p>For PartiQL reads (<code>SELECT</code> statement), if the total number of processed items exceeds the maximum dataset size limit of 1 MB, the read stops and results are returned to the user as a <code>LastEvaluatedKey</code> value to continue the read in a subsequent operation. If the filter criteria in <code>WHERE</code> clause does not match any data, the read will return an empty result set.</p><p>A single <code>SELECT</code> statement response can return up to the maximum number of items (if using the Limit parameter) or a maximum of 1 MB of data (and then apply any filtering to the results using <code>WHERE</code> clause). If <code>LastEvaluatedKey</code> is present in the response, you need to paginate the result set. If <code>NextToken</code> is present, you need to paginate the result set and include <code>NextToken</code>.</p>
 
 @param request A container for the necessary parameters to execute the ExecuteStatement service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorDuplicateItem`.
 
 @see AWSDynamoDBExecuteStatementInput
 @see AWSDynamoDBExecuteStatementOutput
 */
- (void)executeStatement:(AWSDynamoDBExecuteStatementInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBExecuteStatementOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>This operation allows you to perform transactional reads or writes on data stored in DynamoDB, using PartiQL.</p><note><p>The entire transaction must consist of either read statements or write statements, you cannot mix both in one transaction. The EXISTS function is an exception and can be used to check the condition of specific attributes of the item in a similar manner to <code>ConditionCheck</code> in the <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/transaction-apis.html#transaction-apis-txwriteitems">TransactWriteItems</a> API.</p></note>
 
 @param request A container for the necessary parameters to execute the ExecuteTransaction service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBExecuteTransactionOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorTransactionCanceled`, `AWSDynamoDBErrorTransactionInProgress`, `AWSDynamoDBErrorIdempotentParameterMismatch`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBExecuteTransactionInput
 @see AWSDynamoDBExecuteTransactionOutput
 */
- (AWSTask<AWSDynamoDBExecuteTransactionOutput *> *)executeTransaction:(AWSDynamoDBExecuteTransactionInput *)request;

/**
 <p>This operation allows you to perform transactional reads or writes on data stored in DynamoDB, using PartiQL.</p><note><p>The entire transaction must consist of either read statements or write statements, you cannot mix both in one transaction. The EXISTS function is an exception and can be used to check the condition of specific attributes of the item in a similar manner to <code>ConditionCheck</code> in the <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/transaction-apis.html#transaction-apis-txwriteitems">TransactWriteItems</a> API.</p></note>
 
 @param request A container for the necessary parameters to execute the ExecuteTransaction service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorTransactionCanceled`, `AWSDynamoDBErrorTransactionInProgress`, `AWSDynamoDBErrorIdempotentParameterMismatch`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBExecuteTransactionInput
 @see AWSDynamoDBExecuteTransactionOutput
 */
- (void)executeTransaction:(AWSDynamoDBExecuteTransactionInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBExecuteTransactionOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Exports table data to an S3 bucket. The table must have point in time recovery enabled, and you can export data from any time within the point in time recovery window.</p>
 
 @param request A container for the necessary parameters to execute the ExportTableToPointInTime service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBExportTableToPointInTimeOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorPointInTimeRecoveryUnavailable`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInvalidExportTime`, `AWSDynamoDBErrorExportConflict`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBExportTableToPointInTimeInput
 @see AWSDynamoDBExportTableToPointInTimeOutput
 */
- (AWSTask<AWSDynamoDBExportTableToPointInTimeOutput *> *)exportTableToPointInTime:(AWSDynamoDBExportTableToPointInTimeInput *)request;

/**
 <p>Exports table data to an S3 bucket. The table must have point in time recovery enabled, and you can export data from any time within the point in time recovery window.</p>
 
 @param request A container for the necessary parameters to execute the ExportTableToPointInTime service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorPointInTimeRecoveryUnavailable`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInvalidExportTime`, `AWSDynamoDBErrorExportConflict`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBExportTableToPointInTimeInput
 @see AWSDynamoDBExportTableToPointInTimeOutput
 */
- (void)exportTableToPointInTime:(AWSDynamoDBExportTableToPointInTimeInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBExportTableToPointInTimeOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>GetItem</code> operation returns a set of attributes for the item with the given primary key. If there is no matching item, <code>GetItem</code> does not return any data and there will be no <code>Item</code> element in the response.</p><p><code>GetItem</code> provides an eventually consistent read by default. If your application requires a strongly consistent read, set <code>ConsistentRead</code> to <code>true</code>. Although a strongly consistent read might take more time than an eventually consistent read, it always returns the last updated value.</p>
 
 @param request A container for the necessary parameters to execute the GetItem service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBGetItemOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBGetItemInput
 @see AWSDynamoDBGetItemOutput
 */
- (AWSTask<AWSDynamoDBGetItemOutput *> *)getItem:(AWSDynamoDBGetItemInput *)request;

/**
 <p>The <code>GetItem</code> operation returns a set of attributes for the item with the given primary key. If there is no matching item, <code>GetItem</code> does not return any data and there will be no <code>Item</code> element in the response.</p><p><code>GetItem</code> provides an eventually consistent read by default. If your application requires a strongly consistent read, set <code>ConsistentRead</code> to <code>true</code>. Although a strongly consistent read might take more time than an eventually consistent read, it always returns the last updated value.</p>
 
 @param request A container for the necessary parameters to execute the GetItem service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBGetItemInput
 @see AWSDynamoDBGetItemOutput
 */
- (void)getItem:(AWSDynamoDBGetItemInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBGetItemOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Imports table data from an S3 bucket. </p>
 
 @param request A container for the necessary parameters to execute the ImportTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBImportTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorImportConflict`.
 
 @see AWSDynamoDBImportTableInput
 @see AWSDynamoDBImportTableOutput
 */
- (AWSTask<AWSDynamoDBImportTableOutput *> *)importTable:(AWSDynamoDBImportTableInput *)request;

/**
 <p> Imports table data from an S3 bucket. </p>
 
 @param request A container for the necessary parameters to execute the ImportTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorImportConflict`.
 
 @see AWSDynamoDBImportTableInput
 @see AWSDynamoDBImportTableOutput
 */
- (void)importTable:(AWSDynamoDBImportTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBImportTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List DynamoDB backups that are associated with an Amazon Web Services account and weren't made with Amazon Web Services Backup. To list these backups for a given table, specify <code>TableName</code>. <code>ListBackups</code> returns a paginated list of results with at most 1 MB worth of items in a page. You can also specify a maximum number of entries to be returned in a page.</p><p>In the request, start time is inclusive, but end time is exclusive. Note that these boundaries are for the time at which the original backup was requested.</p><p>You can call <code>ListBackups</code> a maximum of five times per second.</p><p>If you want to retrieve the complete list of backups made with Amazon Web Services Backup, use the <a href="https://docs.aws.amazon.com/aws-backup/latest/devguide/API_ListBackupJobs.html">Amazon Web Services Backup list API.</a></p>
 
 @param request A container for the necessary parameters to execute the ListBackups service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListBackupsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListBackupsInput
 @see AWSDynamoDBListBackupsOutput
 */
- (AWSTask<AWSDynamoDBListBackupsOutput *> *)listBackups:(AWSDynamoDBListBackupsInput *)request;

/**
 <p>List DynamoDB backups that are associated with an Amazon Web Services account and weren't made with Amazon Web Services Backup. To list these backups for a given table, specify <code>TableName</code>. <code>ListBackups</code> returns a paginated list of results with at most 1 MB worth of items in a page. You can also specify a maximum number of entries to be returned in a page.</p><p>In the request, start time is inclusive, but end time is exclusive. Note that these boundaries are for the time at which the original backup was requested.</p><p>You can call <code>ListBackups</code> a maximum of five times per second.</p><p>If you want to retrieve the complete list of backups made with Amazon Web Services Backup, use the <a href="https://docs.aws.amazon.com/aws-backup/latest/devguide/API_ListBackupJobs.html">Amazon Web Services Backup list API.</a></p>
 
 @param request A container for the necessary parameters to execute the ListBackups service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListBackupsInput
 @see AWSDynamoDBListBackupsOutput
 */
- (void)listBackups:(AWSDynamoDBListBackupsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListBackupsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns a list of ContributorInsightsSummary for a table and all its global secondary indexes.</p>
 
 @param request A container for the necessary parameters to execute the ListContributorInsights service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListContributorInsightsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListContributorInsightsInput
 @see AWSDynamoDBListContributorInsightsOutput
 */
- (AWSTask<AWSDynamoDBListContributorInsightsOutput *> *)listContributorInsights:(AWSDynamoDBListContributorInsightsInput *)request;

/**
 <p>Returns a list of ContributorInsightsSummary for a table and all its global secondary indexes.</p>
 
 @param request A container for the necessary parameters to execute the ListContributorInsights service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListContributorInsightsInput
 @see AWSDynamoDBListContributorInsightsOutput
 */
- (void)listContributorInsights:(AWSDynamoDBListContributorInsightsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListContributorInsightsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists completed exports within the past 90 days.</p>
 
 @param request A container for the necessary parameters to execute the ListExports service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListExportsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListExportsInput
 @see AWSDynamoDBListExportsOutput
 */
- (AWSTask<AWSDynamoDBListExportsOutput *> *)listExports:(AWSDynamoDBListExportsInput *)request;

/**
 <p>Lists completed exports within the past 90 days.</p>
 
 @param request A container for the necessary parameters to execute the ListExports service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListExportsInput
 @see AWSDynamoDBListExportsOutput
 */
- (void)listExports:(AWSDynamoDBListExportsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListExportsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Lists all global tables that have a replica in the specified Region.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the ListGlobalTables service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListGlobalTablesOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListGlobalTablesInput
 @see AWSDynamoDBListGlobalTablesOutput
 */
- (AWSTask<AWSDynamoDBListGlobalTablesOutput *> *)listGlobalTables:(AWSDynamoDBListGlobalTablesInput *)request;

/**
 <p>Lists all global tables that have a replica in the specified Region.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the ListGlobalTables service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListGlobalTablesInput
 @see AWSDynamoDBListGlobalTablesOutput
 */
- (void)listGlobalTables:(AWSDynamoDBListGlobalTablesInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListGlobalTablesOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p> Lists completed imports within the past 90 days. </p>
 
 @param request A container for the necessary parameters to execute the ListImports service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListImportsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`.
 
 @see AWSDynamoDBListImportsInput
 @see AWSDynamoDBListImportsOutput
 */
- (AWSTask<AWSDynamoDBListImportsOutput *> *)listImports:(AWSDynamoDBListImportsInput *)request;

/**
 <p> Lists completed imports within the past 90 days. </p>
 
 @param request A container for the necessary parameters to execute the ListImports service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`.
 
 @see AWSDynamoDBListImportsInput
 @see AWSDynamoDBListImportsOutput
 */
- (void)listImports:(AWSDynamoDBListImportsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListImportsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Returns an array of table names associated with the current account and endpoint. The output from <code>ListTables</code> is paginated, with each page returning a maximum of 100 table names.</p>
 
 @param request A container for the necessary parameters to execute the ListTables service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListTablesOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListTablesInput
 @see AWSDynamoDBListTablesOutput
 */
- (AWSTask<AWSDynamoDBListTablesOutput *> *)listTables:(AWSDynamoDBListTablesInput *)request;

/**
 <p>Returns an array of table names associated with the current account and endpoint. The output from <code>ListTables</code> is paginated, with each page returning a maximum of 100 table names.</p>
 
 @param request A container for the necessary parameters to execute the ListTables service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListTablesInput
 @see AWSDynamoDBListTablesOutput
 */
- (void)listTables:(AWSDynamoDBListTablesInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListTablesOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>List all tags on an Amazon DynamoDB resource. You can call ListTagsOfResource up to 10 times per second, per account.</p><p>For an overview on tagging DynamoDB resources, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Tagging.html">Tagging for DynamoDB</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the ListTagsOfResource service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBListTagsOfResourceOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListTagsOfResourceInput
 @see AWSDynamoDBListTagsOfResourceOutput
 */
- (AWSTask<AWSDynamoDBListTagsOfResourceOutput *> *)listTagsOfResource:(AWSDynamoDBListTagsOfResourceInput *)request;

/**
 <p>List all tags on an Amazon DynamoDB resource. You can call ListTagsOfResource up to 10 times per second, per account.</p><p>For an overview on tagging DynamoDB resources, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Tagging.html">Tagging for DynamoDB</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the ListTagsOfResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBListTagsOfResourceInput
 @see AWSDynamoDBListTagsOfResourceOutput
 */
- (void)listTagsOfResource:(AWSDynamoDBListTagsOfResourceInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBListTagsOfResourceOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a new item, or replaces an old item with a new item. If an item that has the same primary key as the new item already exists in the specified table, the new item completely replaces the existing item. You can perform a conditional put operation (add a new item if one with the specified primary key doesn't exist), or replace an existing item if it has certain attribute values. You can return the item's attribute values in the same operation, using the <code>ReturnValues</code> parameter.</p><p>When you add an item, the primary key attributes are the only required attributes. </p><p>Empty String and Binary attribute values are allowed. Attribute values of type String and Binary must have a length greater than zero if the attribute is used as a key attribute for a table or index. Set type attributes cannot be empty. </p><p>Invalid Requests with empty values will be rejected with a <code>ValidationException</code> exception.</p><note><p>To prevent a new item from replacing an existing item, use a conditional expression that contains the <code>attribute_not_exists</code> function with the name of the attribute being used as the partition key for the table. Since every record must contain that attribute, the <code>attribute_not_exists</code> function will only succeed if no matching item exists.</p></note><p>For more information about <code>PutItem</code>, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithItems.html">Working with Items</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the PutItem service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBPutItemOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBPutItemInput
 @see AWSDynamoDBPutItemOutput
 */
- (AWSTask<AWSDynamoDBPutItemOutput *> *)putItem:(AWSDynamoDBPutItemInput *)request;

/**
 <p>Creates a new item, or replaces an old item with a new item. If an item that has the same primary key as the new item already exists in the specified table, the new item completely replaces the existing item. You can perform a conditional put operation (add a new item if one with the specified primary key doesn't exist), or replace an existing item if it has certain attribute values. You can return the item's attribute values in the same operation, using the <code>ReturnValues</code> parameter.</p><p>When you add an item, the primary key attributes are the only required attributes. </p><p>Empty String and Binary attribute values are allowed. Attribute values of type String and Binary must have a length greater than zero if the attribute is used as a key attribute for a table or index. Set type attributes cannot be empty. </p><p>Invalid Requests with empty values will be rejected with a <code>ValidationException</code> exception.</p><note><p>To prevent a new item from replacing an existing item, use a conditional expression that contains the <code>attribute_not_exists</code> function with the name of the attribute being used as the partition key for the table. Since every record must contain that attribute, the <code>attribute_not_exists</code> function will only succeed if no matching item exists.</p></note><p>For more information about <code>PutItem</code>, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithItems.html">Working with Items</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the PutItem service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBPutItemInput
 @see AWSDynamoDBPutItemOutput
 */
- (void)putItem:(AWSDynamoDBPutItemInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBPutItemOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>You must provide the name of the partition key attribute and a single value for that attribute. <code>Query</code> returns all items with that partition key value. Optionally, you can provide a sort key attribute and use a comparison operator to refine the search results.</p><p>Use the <code>KeyConditionExpression</code> parameter to provide a specific value for the partition key. The <code>Query</code> operation will return all of the items from the table or index with that partition key value. You can optionally narrow the scope of the <code>Query</code> operation by specifying a sort key value and a comparison operator in <code>KeyConditionExpression</code>. To further refine the <code>Query</code> results, you can optionally provide a <code>FilterExpression</code>. A <code>FilterExpression</code> determines which items within the results should be returned to you. All of the other results are discarded. </p><p> A <code>Query</code> operation always returns a result set. If no matching items are found, the result set will be empty. Queries that do not return results consume the minimum number of read capacity units for that type of read operation. </p><note><p> DynamoDB calculates the number of read capacity units consumed based on item size, not on the amount of data that is returned to an application. The number of capacity units consumed will be the same whether you request all of the attributes (the default behavior) or just some of them (using a projection expression). The number will also be the same whether or not you use a <code>FilterExpression</code>. </p></note><p><code>Query</code> results are always sorted by the sort key value. If the data type of the sort key is Number, the results are returned in numeric order; otherwise, the results are returned in order of UTF-8 bytes. By default, the sort order is ascending. To reverse the order, set the <code>ScanIndexForward</code> parameter to false. </p><p> A single <code>Query</code> operation will read up to the maximum number of items set (if using the <code>Limit</code> parameter) or a maximum of 1 MB of data and then apply any filtering to the results using <code>FilterExpression</code>. If <code>LastEvaluatedKey</code> is present in the response, you will need to paginate the result set. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Query.html#Query.Pagination">Paginating the Results</a> in the <i>Amazon DynamoDB Developer Guide</i>. </p><p><code>FilterExpression</code> is applied after a <code>Query</code> finishes, but before the results are returned. A <code>FilterExpression</code> cannot contain partition key or sort key attributes. You need to specify those attributes in the <code>KeyConditionExpression</code>. </p><note><p> A <code>Query</code> operation can return an empty result set and a <code>LastEvaluatedKey</code> if all the items read for the page of results are filtered out. </p></note><p>You can query a table, a local secondary index, or a global secondary index. For a query on a table or on a local secondary index, you can set the <code>ConsistentRead</code> parameter to <code>true</code> and obtain a strongly consistent result. Global secondary indexes support eventually consistent reads only, so do not specify <code>ConsistentRead</code> when querying a global secondary index.</p>
 
 @param request A container for the necessary parameters to execute the Query service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBQueryOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBQueryInput
 @see AWSDynamoDBQueryOutput
 */
- (AWSTask<AWSDynamoDBQueryOutput *> *)query:(AWSDynamoDBQueryInput *)request;

/**
 <p>You must provide the name of the partition key attribute and a single value for that attribute. <code>Query</code> returns all items with that partition key value. Optionally, you can provide a sort key attribute and use a comparison operator to refine the search results.</p><p>Use the <code>KeyConditionExpression</code> parameter to provide a specific value for the partition key. The <code>Query</code> operation will return all of the items from the table or index with that partition key value. You can optionally narrow the scope of the <code>Query</code> operation by specifying a sort key value and a comparison operator in <code>KeyConditionExpression</code>. To further refine the <code>Query</code> results, you can optionally provide a <code>FilterExpression</code>. A <code>FilterExpression</code> determines which items within the results should be returned to you. All of the other results are discarded. </p><p> A <code>Query</code> operation always returns a result set. If no matching items are found, the result set will be empty. Queries that do not return results consume the minimum number of read capacity units for that type of read operation. </p><note><p> DynamoDB calculates the number of read capacity units consumed based on item size, not on the amount of data that is returned to an application. The number of capacity units consumed will be the same whether you request all of the attributes (the default behavior) or just some of them (using a projection expression). The number will also be the same whether or not you use a <code>FilterExpression</code>. </p></note><p><code>Query</code> results are always sorted by the sort key value. If the data type of the sort key is Number, the results are returned in numeric order; otherwise, the results are returned in order of UTF-8 bytes. By default, the sort order is ascending. To reverse the order, set the <code>ScanIndexForward</code> parameter to false. </p><p> A single <code>Query</code> operation will read up to the maximum number of items set (if using the <code>Limit</code> parameter) or a maximum of 1 MB of data and then apply any filtering to the results using <code>FilterExpression</code>. If <code>LastEvaluatedKey</code> is present in the response, you will need to paginate the result set. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Query.html#Query.Pagination">Paginating the Results</a> in the <i>Amazon DynamoDB Developer Guide</i>. </p><p><code>FilterExpression</code> is applied after a <code>Query</code> finishes, but before the results are returned. A <code>FilterExpression</code> cannot contain partition key or sort key attributes. You need to specify those attributes in the <code>KeyConditionExpression</code>. </p><note><p> A <code>Query</code> operation can return an empty result set and a <code>LastEvaluatedKey</code> if all the items read for the page of results are filtered out. </p></note><p>You can query a table, a local secondary index, or a global secondary index. For a query on a table or on a local secondary index, you can set the <code>ConsistentRead</code> parameter to <code>true</code> and obtain a strongly consistent result. Global secondary indexes support eventually consistent reads only, so do not specify <code>ConsistentRead</code> when querying a global secondary index.</p>
 
 @param request A container for the necessary parameters to execute the Query service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBQueryInput
 @see AWSDynamoDBQueryOutput
 */
- (void)query:(AWSDynamoDBQueryInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBQueryOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Creates a new table from an existing backup. Any number of users can execute up to 50 concurrent restores (any type of restore) in a given account. </p><p>You can call <code>RestoreTableFromBackup</code> at a maximum rate of 10 times per second.</p><p>You must manually set up the following on the restored table:</p><ul><li><p>Auto scaling policies</p></li><li><p>IAM policies</p></li><li><p>Amazon CloudWatch metrics and alarms</p></li><li><p>Tags</p></li><li><p>Stream settings</p></li><li><p>Time to Live (TTL) settings</p></li></ul>
 
 @param request A container for the necessary parameters to execute the RestoreTableFromBackup service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBRestoreTableFromBackupOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableAlreadyExists`, `AWSDynamoDBErrorTableInUse`, `AWSDynamoDBErrorBackupNotFound`, `AWSDynamoDBErrorBackupInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBRestoreTableFromBackupInput
 @see AWSDynamoDBRestoreTableFromBackupOutput
 */
- (AWSTask<AWSDynamoDBRestoreTableFromBackupOutput *> *)restoreTableFromBackup:(AWSDynamoDBRestoreTableFromBackupInput *)request;

/**
 <p>Creates a new table from an existing backup. Any number of users can execute up to 50 concurrent restores (any type of restore) in a given account. </p><p>You can call <code>RestoreTableFromBackup</code> at a maximum rate of 10 times per second.</p><p>You must manually set up the following on the restored table:</p><ul><li><p>Auto scaling policies</p></li><li><p>IAM policies</p></li><li><p>Amazon CloudWatch metrics and alarms</p></li><li><p>Tags</p></li><li><p>Stream settings</p></li><li><p>Time to Live (TTL) settings</p></li></ul>
 
 @param request A container for the necessary parameters to execute the RestoreTableFromBackup service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableAlreadyExists`, `AWSDynamoDBErrorTableInUse`, `AWSDynamoDBErrorBackupNotFound`, `AWSDynamoDBErrorBackupInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBRestoreTableFromBackupInput
 @see AWSDynamoDBRestoreTableFromBackupOutput
 */
- (void)restoreTableFromBackup:(AWSDynamoDBRestoreTableFromBackupInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBRestoreTableFromBackupOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Restores the specified table to the specified point in time within <code>EarliestRestorableDateTime</code> and <code>LatestRestorableDateTime</code>. You can restore your table to any point in time during the last 35 days. Any number of users can execute up to 4 concurrent restores (any type of restore) in a given account. </p><p> When you restore using point in time recovery, DynamoDB restores your table data to the state based on the selected date and time (day:hour:minute:second) to a new table. </p><p> Along with data, the following are also included on the new restored table using point in time recovery: </p><ul><li><p>Global secondary indexes (GSIs)</p></li><li><p>Local secondary indexes (LSIs)</p></li><li><p>Provisioned read and write capacity</p></li><li><p>Encryption settings</p><important><p> All these settings come from the current settings of the source table at the time of restore. </p></important></li></ul><p>You must manually set up the following on the restored table:</p><ul><li><p>Auto scaling policies</p></li><li><p>IAM policies</p></li><li><p>Amazon CloudWatch metrics and alarms</p></li><li><p>Tags</p></li><li><p>Stream settings</p></li><li><p>Time to Live (TTL) settings</p></li><li><p>Point in time recovery settings</p></li></ul>
 
 @param request A container for the necessary parameters to execute the RestoreTableToPointInTime service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBRestoreTableToPointInTimeOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableAlreadyExists`, `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorTableInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInvalidRestoreTime`, `AWSDynamoDBErrorPointInTimeRecoveryUnavailable`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBRestoreTableToPointInTimeInput
 @see AWSDynamoDBRestoreTableToPointInTimeOutput
 */
- (AWSTask<AWSDynamoDBRestoreTableToPointInTimeOutput *> *)restoreTableToPointInTime:(AWSDynamoDBRestoreTableToPointInTimeInput *)request;

/**
 <p>Restores the specified table to the specified point in time within <code>EarliestRestorableDateTime</code> and <code>LatestRestorableDateTime</code>. You can restore your table to any point in time during the last 35 days. Any number of users can execute up to 4 concurrent restores (any type of restore) in a given account. </p><p> When you restore using point in time recovery, DynamoDB restores your table data to the state based on the selected date and time (day:hour:minute:second) to a new table. </p><p> Along with data, the following are also included on the new restored table using point in time recovery: </p><ul><li><p>Global secondary indexes (GSIs)</p></li><li><p>Local secondary indexes (LSIs)</p></li><li><p>Provisioned read and write capacity</p></li><li><p>Encryption settings</p><important><p> All these settings come from the current settings of the source table at the time of restore. </p></important></li></ul><p>You must manually set up the following on the restored table:</p><ul><li><p>Auto scaling policies</p></li><li><p>IAM policies</p></li><li><p>Amazon CloudWatch metrics and alarms</p></li><li><p>Tags</p></li><li><p>Stream settings</p></li><li><p>Time to Live (TTL) settings</p></li><li><p>Point in time recovery settings</p></li></ul>
 
 @param request A container for the necessary parameters to execute the RestoreTableToPointInTime service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableAlreadyExists`, `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorTableInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInvalidRestoreTime`, `AWSDynamoDBErrorPointInTimeRecoveryUnavailable`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBRestoreTableToPointInTimeInput
 @see AWSDynamoDBRestoreTableToPointInTimeOutput
 */
- (void)restoreTableToPointInTime:(AWSDynamoDBRestoreTableToPointInTimeInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBRestoreTableToPointInTimeOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>Scan</code> operation returns one or more items and item attributes by accessing every item in a table or a secondary index. To have DynamoDB return fewer items, you can provide a <code>FilterExpression</code> operation.</p><p>If the total size of scanned items exceeds the maximum dataset size limit of 1 MB, the scan completes and results are returned to the user. The <code>LastEvaluatedKey</code> value is also returned and the requestor can use the <code>LastEvaluatedKey</code> to continue the scan in a subsequent operation. Each scan response also includes number of items that were scanned (ScannedCount) as part of the request. If using a <code>FilterExpression</code>, a scan result can result in no items meeting the criteria and the <code>Count</code> will result in zero. If you did not use a <code>FilterExpression</code> in the scan request, then <code>Count</code> is the same as <code>ScannedCount</code>.</p><note><p><code>Count</code> and <code>ScannedCount</code> only return the count of items specific to a single scan request and, unless the table is less than 1MB, do not represent the total number of items in the table. </p></note><p>A single <code>Scan</code> operation first reads up to the maximum number of items set (if using the <code>Limit</code> parameter) or a maximum of 1 MB of data and then applies any filtering to the results if a <code>FilterExpression</code> is provided. If <code>LastEvaluatedKey</code> is present in the response, pagination is required to complete the full table scan. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Scan.html#Scan.Pagination">Paginating the Results</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p><p><code>Scan</code> operations proceed sequentially; however, for faster performance on a large table or secondary index, applications can request a parallel <code>Scan</code> operation by providing the <code>Segment</code> and <code>TotalSegments</code> parameters. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Scan.html#Scan.ParallelScan">Parallel Scan</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p><p>By default, a <code>Scan</code> uses eventually consistent reads when accessing the items in a table. Therefore, the results from an eventually consistent <code>Scan</code> may not include the latest item changes at the time the scan iterates through each item in the table. If you require a strongly consistent read of each item as the scan iterates through the items in the table, you can set the <code>ConsistentRead</code> parameter to true. Strong consistency only relates to the consistency of the read at the item level.</p><note><p> DynamoDB does not provide snapshot isolation for a scan operation when the <code>ConsistentRead</code> parameter is set to true. Thus, a DynamoDB scan operation does not guarantee that all reads in a scan see a consistent snapshot of the table when the scan operation was requested. </p></note>
 
 @param request A container for the necessary parameters to execute the Scan service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBScanOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBScanInput
 @see AWSDynamoDBScanOutput
 */
- (AWSTask<AWSDynamoDBScanOutput *> *)scan:(AWSDynamoDBScanInput *)request;

/**
 <p>The <code>Scan</code> operation returns one or more items and item attributes by accessing every item in a table or a secondary index. To have DynamoDB return fewer items, you can provide a <code>FilterExpression</code> operation.</p><p>If the total size of scanned items exceeds the maximum dataset size limit of 1 MB, the scan completes and results are returned to the user. The <code>LastEvaluatedKey</code> value is also returned and the requestor can use the <code>LastEvaluatedKey</code> to continue the scan in a subsequent operation. Each scan response also includes number of items that were scanned (ScannedCount) as part of the request. If using a <code>FilterExpression</code>, a scan result can result in no items meeting the criteria and the <code>Count</code> will result in zero. If you did not use a <code>FilterExpression</code> in the scan request, then <code>Count</code> is the same as <code>ScannedCount</code>.</p><note><p><code>Count</code> and <code>ScannedCount</code> only return the count of items specific to a single scan request and, unless the table is less than 1MB, do not represent the total number of items in the table. </p></note><p>A single <code>Scan</code> operation first reads up to the maximum number of items set (if using the <code>Limit</code> parameter) or a maximum of 1 MB of data and then applies any filtering to the results if a <code>FilterExpression</code> is provided. If <code>LastEvaluatedKey</code> is present in the response, pagination is required to complete the full table scan. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Scan.html#Scan.Pagination">Paginating the Results</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p><p><code>Scan</code> operations proceed sequentially; however, for faster performance on a large table or secondary index, applications can request a parallel <code>Scan</code> operation by providing the <code>Segment</code> and <code>TotalSegments</code> parameters. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Scan.html#Scan.ParallelScan">Parallel Scan</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p><p>By default, a <code>Scan</code> uses eventually consistent reads when accessing the items in a table. Therefore, the results from an eventually consistent <code>Scan</code> may not include the latest item changes at the time the scan iterates through each item in the table. If you require a strongly consistent read of each item as the scan iterates through the items in the table, you can set the <code>ConsistentRead</code> parameter to true. Strong consistency only relates to the consistency of the read at the item level.</p><note><p> DynamoDB does not provide snapshot isolation for a scan operation when the <code>ConsistentRead</code> parameter is set to true. Thus, a DynamoDB scan operation does not guarantee that all reads in a scan see a consistent snapshot of the table when the scan operation was requested. </p></note>
 
 @param request A container for the necessary parameters to execute the Scan service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBScanInput
 @see AWSDynamoDBScanOutput
 */
- (void)scan:(AWSDynamoDBScanInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBScanOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Associate a set of tags with an Amazon DynamoDB resource. You can then activate these user-defined tags so that they appear on the Billing and Cost Management console for cost allocation tracking. You can call TagResource up to five times per second, per account. </p><p>For an overview on tagging DynamoDB resources, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Tagging.html">Tagging for DynamoDB</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the TagResource service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorResourceInUse`.
 
 @see AWSDynamoDBTagResourceInput
 */
- (AWSTask *)tagResource:(AWSDynamoDBTagResourceInput *)request;

/**
 <p>Associate a set of tags with an Amazon DynamoDB resource. You can then activate these user-defined tags so that they appear on the Billing and Cost Management console for cost allocation tracking. You can call TagResource up to five times per second, per account. </p><p>For an overview on tagging DynamoDB resources, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Tagging.html">Tagging for DynamoDB</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the TagResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorResourceInUse`.
 
 @see AWSDynamoDBTagResourceInput
 */
- (void)tagResource:(AWSDynamoDBTagResourceInput *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p><code>TransactGetItems</code> is a synchronous operation that atomically retrieves multiple items from one or more tables (but not from indexes) in a single account and Region. A <code>TransactGetItems</code> call can contain up to 100 <code>TransactGetItem</code> objects, each of which contains a <code>Get</code> structure that specifies an item to retrieve from a table in the account and Region. A call to <code>TransactGetItems</code> cannot retrieve items from tables in more than one Amazon Web Services account or Region. The aggregate size of the items in the transaction cannot exceed 4 MB.</p><p>DynamoDB rejects the entire <code>TransactGetItems</code> request if any of the following is true:</p><ul><li><p>A conflicting operation is in the process of updating an item to be read.</p></li><li><p>There is insufficient provisioned capacity for the transaction to be completed.</p></li><li><p>There is a user error, such as an invalid data format.</p></li><li><p>The aggregate size of the items in the transaction exceeded 4 MB.</p></li></ul>
 
 @param request A container for the necessary parameters to execute the TransactGetItems service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBTransactGetItemsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorTransactionCanceled`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBTransactGetItemsInput
 @see AWSDynamoDBTransactGetItemsOutput
 */
- (AWSTask<AWSDynamoDBTransactGetItemsOutput *> *)transactGetItems:(AWSDynamoDBTransactGetItemsInput *)request;

/**
 <p><code>TransactGetItems</code> is a synchronous operation that atomically retrieves multiple items from one or more tables (but not from indexes) in a single account and Region. A <code>TransactGetItems</code> call can contain up to 100 <code>TransactGetItem</code> objects, each of which contains a <code>Get</code> structure that specifies an item to retrieve from a table in the account and Region. A call to <code>TransactGetItems</code> cannot retrieve items from tables in more than one Amazon Web Services account or Region. The aggregate size of the items in the transaction cannot exceed 4 MB.</p><p>DynamoDB rejects the entire <code>TransactGetItems</code> request if any of the following is true:</p><ul><li><p>A conflicting operation is in the process of updating an item to be read.</p></li><li><p>There is insufficient provisioned capacity for the transaction to be completed.</p></li><li><p>There is a user error, such as an invalid data format.</p></li><li><p>The aggregate size of the items in the transaction exceeded 4 MB.</p></li></ul>
 
 @param request A container for the necessary parameters to execute the TransactGetItems service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorTransactionCanceled`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBTransactGetItemsInput
 @see AWSDynamoDBTransactGetItemsOutput
 */
- (void)transactGetItems:(AWSDynamoDBTransactGetItemsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBTransactGetItemsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p><code>TransactWriteItems</code> is a synchronous write operation that groups up to 100 action requests. These actions can target items in different tables, but not in different Amazon Web Services accounts or Regions, and no two actions can target the same item. For example, you cannot both <code>ConditionCheck</code> and <code>Update</code> the same item. The aggregate size of the items in the transaction cannot exceed 4 MB.</p><p>The actions are completed atomically so that either all of them succeed, or all of them fail. They are defined by the following objects:</p><ul><li><p><code>Put</code>  —   Initiates a <code>PutItem</code> operation to write a new item. This structure specifies the primary key of the item to be written, the name of the table to write it in, an optional condition expression that must be satisfied for the write to succeed, a list of the item's attributes, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li><li><p><code>Update</code>  —   Initiates an <code>UpdateItem</code> operation to update an existing item. This structure specifies the primary key of the item to be updated, the name of the table where it resides, an optional condition expression that must be satisfied for the update to succeed, an expression that defines one or more attributes to be updated, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li><li><p><code>Delete</code>  —   Initiates a <code>DeleteItem</code> operation to delete an existing item. This structure specifies the primary key of the item to be deleted, the name of the table where it resides, an optional condition expression that must be satisfied for the deletion to succeed, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li><li><p><code>ConditionCheck</code>  —   Applies a condition to an item that is not being modified by the transaction. This structure specifies the primary key of the item to be checked, the name of the table where it resides, a condition expression that must be satisfied for the transaction to succeed, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li></ul><p>DynamoDB rejects the entire <code>TransactWriteItems</code> request if any of the following is true:</p><ul><li><p>A condition in one of the condition expressions is not met.</p></li><li><p>An ongoing operation is in the process of updating the same item.</p></li><li><p>There is insufficient provisioned capacity for the transaction to be completed.</p></li><li><p>An item size becomes too large (bigger than 400 KB), a local secondary index (LSI) becomes too large, or a similar validation error occurs because of changes made by the transaction.</p></li><li><p>The aggregate size of the items in the transaction exceeds 4 MB.</p></li><li><p>There is a user error, such as an invalid data format.</p></li></ul>
 
 @param request A container for the necessary parameters to execute the TransactWriteItems service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBTransactWriteItemsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorTransactionCanceled`, `AWSDynamoDBErrorTransactionInProgress`, `AWSDynamoDBErrorIdempotentParameterMismatch`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBTransactWriteItemsInput
 @see AWSDynamoDBTransactWriteItemsOutput
 */
- (AWSTask<AWSDynamoDBTransactWriteItemsOutput *> *)transactWriteItems:(AWSDynamoDBTransactWriteItemsInput *)request;

/**
 <p><code>TransactWriteItems</code> is a synchronous write operation that groups up to 100 action requests. These actions can target items in different tables, but not in different Amazon Web Services accounts or Regions, and no two actions can target the same item. For example, you cannot both <code>ConditionCheck</code> and <code>Update</code> the same item. The aggregate size of the items in the transaction cannot exceed 4 MB.</p><p>The actions are completed atomically so that either all of them succeed, or all of them fail. They are defined by the following objects:</p><ul><li><p><code>Put</code>  —   Initiates a <code>PutItem</code> operation to write a new item. This structure specifies the primary key of the item to be written, the name of the table to write it in, an optional condition expression that must be satisfied for the write to succeed, a list of the item's attributes, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li><li><p><code>Update</code>  —   Initiates an <code>UpdateItem</code> operation to update an existing item. This structure specifies the primary key of the item to be updated, the name of the table where it resides, an optional condition expression that must be satisfied for the update to succeed, an expression that defines one or more attributes to be updated, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li><li><p><code>Delete</code>  —   Initiates a <code>DeleteItem</code> operation to delete an existing item. This structure specifies the primary key of the item to be deleted, the name of the table where it resides, an optional condition expression that must be satisfied for the deletion to succeed, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li><li><p><code>ConditionCheck</code>  —   Applies a condition to an item that is not being modified by the transaction. This structure specifies the primary key of the item to be checked, the name of the table where it resides, a condition expression that must be satisfied for the transaction to succeed, and a field indicating whether to retrieve the item's attributes if the condition is not met.</p></li></ul><p>DynamoDB rejects the entire <code>TransactWriteItems</code> request if any of the following is true:</p><ul><li><p>A condition in one of the condition expressions is not met.</p></li><li><p>An ongoing operation is in the process of updating the same item.</p></li><li><p>There is insufficient provisioned capacity for the transaction to be completed.</p></li><li><p>An item size becomes too large (bigger than 400 KB), a local secondary index (LSI) becomes too large, or a similar validation error occurs because of changes made by the transaction.</p></li><li><p>The aggregate size of the items in the transaction exceeds 4 MB.</p></li><li><p>There is a user error, such as an invalid data format.</p></li></ul>
 
 @param request A container for the necessary parameters to execute the TransactWriteItems service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorTransactionCanceled`, `AWSDynamoDBErrorTransactionInProgress`, `AWSDynamoDBErrorIdempotentParameterMismatch`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBTransactWriteItemsInput
 @see AWSDynamoDBTransactWriteItemsOutput
 */
- (void)transactWriteItems:(AWSDynamoDBTransactWriteItemsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBTransactWriteItemsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Removes the association of tags from an Amazon DynamoDB resource. You can call <code>UntagResource</code> up to five times per second, per account. </p><p>For an overview on tagging DynamoDB resources, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Tagging.html">Tagging for DynamoDB</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the UntagResource service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will be `nil`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorResourceInUse`.
 
 @see AWSDynamoDBUntagResourceInput
 */
- (AWSTask *)untagResource:(AWSDynamoDBUntagResourceInput *)request;

/**
 <p>Removes the association of tags from an Amazon DynamoDB resource. You can call <code>UntagResource</code> up to five times per second, per account. </p><p>For an overview on tagging DynamoDB resources, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Tagging.html">Tagging for DynamoDB</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
 
 @param request A container for the necessary parameters to execute the UntagResource service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorResourceInUse`.
 
 @see AWSDynamoDBUntagResourceInput
 */
- (void)untagResource:(AWSDynamoDBUntagResourceInput *)request completionHandler:(void (^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 <p><code>UpdateContinuousBackups</code> enables or disables point in time recovery for the specified table. A successful <code>UpdateContinuousBackups</code> call returns the current <code>ContinuousBackupsDescription</code>. Continuous backups are <code>ENABLED</code> on all tables at table creation. If point in time recovery is enabled, <code>PointInTimeRecoveryStatus</code> will be set to ENABLED.</p><p> Once continuous backups and point in time recovery are enabled, you can restore to any point in time within <code>EarliestRestorableDateTime</code> and <code>LatestRestorableDateTime</code>. </p><p><code>LatestRestorableDateTime</code> is typically 5 minutes before the current time. You can restore your table to any point in time during the last 35 days. </p>
 
 @param request A container for the necessary parameters to execute the UpdateContinuousBackups service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateContinuousBackupsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorContinuousBackupsUnavailable`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateContinuousBackupsInput
 @see AWSDynamoDBUpdateContinuousBackupsOutput
 */
- (AWSTask<AWSDynamoDBUpdateContinuousBackupsOutput *> *)updateContinuousBackups:(AWSDynamoDBUpdateContinuousBackupsInput *)request;

/**
 <p><code>UpdateContinuousBackups</code> enables or disables point in time recovery for the specified table. A successful <code>UpdateContinuousBackups</code> call returns the current <code>ContinuousBackupsDescription</code>. Continuous backups are <code>ENABLED</code> on all tables at table creation. If point in time recovery is enabled, <code>PointInTimeRecoveryStatus</code> will be set to ENABLED.</p><p> Once continuous backups and point in time recovery are enabled, you can restore to any point in time within <code>EarliestRestorableDateTime</code> and <code>LatestRestorableDateTime</code>. </p><p><code>LatestRestorableDateTime</code> is typically 5 minutes before the current time. You can restore your table to any point in time during the last 35 days. </p>
 
 @param request A container for the necessary parameters to execute the UpdateContinuousBackups service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorTableNotFound`, `AWSDynamoDBErrorContinuousBackupsUnavailable`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateContinuousBackupsInput
 @see AWSDynamoDBUpdateContinuousBackupsOutput
 */
- (void)updateContinuousBackups:(AWSDynamoDBUpdateContinuousBackupsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateContinuousBackupsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates the status for contributor insights for a specific table or index. CloudWatch Contributor Insights for DynamoDB graphs display the partition key and (if applicable) sort key of frequently accessed items and frequently throttled items in plaintext. If you require the use of Amazon Web Services Key Management Service (KMS) to encrypt this table’s partition key and sort key data with an Amazon Web Services managed key or customer managed key, you should not enable CloudWatch Contributor Insights for DynamoDB for this table.</p>
 
 @param request A container for the necessary parameters to execute the UpdateContributorInsights service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateContributorInsightsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateContributorInsightsInput
 @see AWSDynamoDBUpdateContributorInsightsOutput
 */
- (AWSTask<AWSDynamoDBUpdateContributorInsightsOutput *> *)updateContributorInsights:(AWSDynamoDBUpdateContributorInsightsInput *)request;

/**
 <p>Updates the status for contributor insights for a specific table or index. CloudWatch Contributor Insights for DynamoDB graphs display the partition key and (if applicable) sort key of frequently accessed items and frequently throttled items in plaintext. If you require the use of Amazon Web Services Key Management Service (KMS) to encrypt this table’s partition key and sort key data with an Amazon Web Services managed key or customer managed key, you should not enable CloudWatch Contributor Insights for DynamoDB for this table.</p>
 
 @param request A container for the necessary parameters to execute the UpdateContributorInsights service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateContributorInsightsInput
 @see AWSDynamoDBUpdateContributorInsightsOutput
 */
- (void)updateContributorInsights:(AWSDynamoDBUpdateContributorInsightsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateContributorInsightsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Adds or removes replicas in the specified global table. The global table must already exist to be able to use this operation. Any replica to be added must be empty, have the same name as the global table, have the same key schema, have DynamoDB Streams enabled, and have the same provisioned and maximum write capacity units.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important><note><p> This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29</a> of global tables. If you are using global tables <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21</a> you can use <a href="https://docs.aws.amazon.com/amazondynamodb/latest/APIReference/API_DescribeTable.html">DescribeTable</a> instead. </p><p> Although you can use <code>UpdateGlobalTable</code> to add replicas and remove replicas in a single request, for simplicity we recommend that you issue separate requests for adding or removing replicas. </p></note><p> If global secondary indexes are specified, then the following conditions must also be met: </p><ul><li><p> The global secondary indexes must have the same name. </p></li><li><p> The global secondary indexes must have the same hash key and sort key (if present). </p></li><li><p> The global secondary indexes must have the same provisioned and maximum write capacity units. </p></li></ul>
 
 @param request A container for the necessary parameters to execute the UpdateGlobalTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateGlobalTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorGlobalTableNotFound`, `AWSDynamoDBErrorReplicaAlreadyExists`, `AWSDynamoDBErrorReplicaNotFound`, `AWSDynamoDBErrorTableNotFound`.
 
 @see AWSDynamoDBUpdateGlobalTableInput
 @see AWSDynamoDBUpdateGlobalTableOutput
 */
- (AWSTask<AWSDynamoDBUpdateGlobalTableOutput *> *)updateGlobalTable:(AWSDynamoDBUpdateGlobalTableInput *)request;

/**
 <p>Adds or removes replicas in the specified global table. The global table must already exist to be able to use this operation. Any replica to be added must be empty, have the same name as the global table, have the same key schema, have DynamoDB Streams enabled, and have the same provisioned and maximum write capacity units.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important><note><p> This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29</a> of global tables. If you are using global tables <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21</a> you can use <a href="https://docs.aws.amazon.com/amazondynamodb/latest/APIReference/API_DescribeTable.html">DescribeTable</a> instead. </p><p> Although you can use <code>UpdateGlobalTable</code> to add replicas and remove replicas in a single request, for simplicity we recommend that you issue separate requests for adding or removing replicas. </p></note><p> If global secondary indexes are specified, then the following conditions must also be met: </p><ul><li><p> The global secondary indexes must have the same name. </p></li><li><p> The global secondary indexes must have the same hash key and sort key (if present). </p></li><li><p> The global secondary indexes must have the same provisioned and maximum write capacity units. </p></li></ul>
 
 @param request A container for the necessary parameters to execute the UpdateGlobalTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorInternalServer`, `AWSDynamoDBErrorGlobalTableNotFound`, `AWSDynamoDBErrorReplicaAlreadyExists`, `AWSDynamoDBErrorReplicaNotFound`, `AWSDynamoDBErrorTableNotFound`.
 
 @see AWSDynamoDBUpdateGlobalTableInput
 @see AWSDynamoDBUpdateGlobalTableOutput
 */
- (void)updateGlobalTable:(AWSDynamoDBUpdateGlobalTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateGlobalTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates settings for a global table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the UpdateGlobalTableSettings service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateGlobalTableSettingsOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorGlobalTableNotFound`, `AWSDynamoDBErrorReplicaNotFound`, `AWSDynamoDBErrorIndexNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateGlobalTableSettingsInput
 @see AWSDynamoDBUpdateGlobalTableSettingsOutput
 */
- (AWSTask<AWSDynamoDBUpdateGlobalTableSettingsOutput *> *)updateGlobalTableSettings:(AWSDynamoDBUpdateGlobalTableSettingsInput *)request;

/**
 <p>Updates settings for a global table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V1.html">Version 2017.11.29 (Legacy)</a> of global tables. We recommend using <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> when creating new global tables, as it provides greater flexibility, higher efficiency and consumes less write capacity than 2017.11.29 (Legacy). To determine which version you are using, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.DetermineVersion.html">Determining the version</a>. To update existing global tables from version 2017.11.29 (Legacy) to version 2019.11.21 (Current), see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/V2globaltables_upgrade.html"> Updating global tables</a>. </p></important>
 
 @param request A container for the necessary parameters to execute the UpdateGlobalTableSettings service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorGlobalTableNotFound`, `AWSDynamoDBErrorReplicaNotFound`, `AWSDynamoDBErrorIndexNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateGlobalTableSettingsInput
 @see AWSDynamoDBUpdateGlobalTableSettingsOutput
 */
- (void)updateGlobalTableSettings:(AWSDynamoDBUpdateGlobalTableSettingsInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateGlobalTableSettingsOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Edits an existing item's attributes, or adds a new item to the table if it does not already exist. You can put, delete, or add attribute values. You can also perform a conditional update on an existing item (insert a new attribute name-value pair if it doesn't exist, or replace an existing name-value pair if it has certain expected attribute values).</p><p>You can also return the item's attribute values in the same <code>UpdateItem</code> operation using the <code>ReturnValues</code> parameter.</p>
 
 @param request A container for the necessary parameters to execute the UpdateItem service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateItemOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateItemInput
 @see AWSDynamoDBUpdateItemOutput
 */
- (AWSTask<AWSDynamoDBUpdateItemOutput *> *)updateItem:(AWSDynamoDBUpdateItemInput *)request;

/**
 <p>Edits an existing item's attributes, or adds a new item to the table if it does not already exist. You can put, delete, or add attribute values. You can also perform a conditional update on an existing item (insert a new attribute name-value pair if it doesn't exist, or replace an existing name-value pair if it has certain expected attribute values).</p><p>You can also return the item's attribute values in the same <code>UpdateItem</code> operation using the <code>ReturnValues</code> parameter.</p>
 
 @param request A container for the necessary parameters to execute the UpdateItem service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorConditionalCheckFailed`, `AWSDynamoDBErrorProvisionedThroughputExceeded`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorItemCollectionSizeLimitExceeded`, `AWSDynamoDBErrorTransactionConflict`, `AWSDynamoDBErrorRequestLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateItemInput
 @see AWSDynamoDBUpdateItemOutput
 */
- (void)updateItem:(AWSDynamoDBUpdateItemInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateItemOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Modifies the provisioned throughput settings, global secondary indexes, or DynamoDB Streams settings for a given table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important><p>You can only perform one of the following operations at once:</p><ul><li><p>Modify the provisioned throughput settings of the table.</p></li><li><p>Remove a global secondary index from the table.</p></li><li><p>Create a new global secondary index on the table. After the index begins backfilling, you can use <code>UpdateTable</code> to perform other operations.</p></li></ul><p><code>UpdateTable</code> is an asynchronous operation; while it is executing, the table status changes from <code>ACTIVE</code> to <code>UPDATING</code>. While it is <code>UPDATING</code>, you cannot issue another <code>UpdateTable</code> request. When the table returns to the <code>ACTIVE</code> state, the <code>UpdateTable</code> operation is complete.</p>
 
 @param request A container for the necessary parameters to execute the UpdateTable service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateTableOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateTableInput
 @see AWSDynamoDBUpdateTableOutput
 */
- (AWSTask<AWSDynamoDBUpdateTableOutput *> *)updateTable:(AWSDynamoDBUpdateTableInput *)request;

/**
 <p>Modifies the provisioned throughput settings, global secondary indexes, or DynamoDB Streams settings for a given table.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important><p>You can only perform one of the following operations at once:</p><ul><li><p>Modify the provisioned throughput settings of the table.</p></li><li><p>Remove a global secondary index from the table.</p></li><li><p>Create a new global secondary index on the table. After the index begins backfilling, you can use <code>UpdateTable</code> to perform other operations.</p></li></ul><p><code>UpdateTable</code> is an asynchronous operation; while it is executing, the table status changes from <code>ACTIVE</code> to <code>UPDATING</code>. While it is <code>UPDATING</code>, you cannot issue another <code>UpdateTable</code> request. When the table returns to the <code>ACTIVE</code> state, the <code>UpdateTable</code> operation is complete.</p>
 
 @param request A container for the necessary parameters to execute the UpdateTable service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateTableInput
 @see AWSDynamoDBUpdateTableOutput
 */
- (void)updateTable:(AWSDynamoDBUpdateTableInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateTableOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>Updates auto scaling settings on your global tables at once.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important>
 
 @param request A container for the necessary parameters to execute the UpdateTableReplicaAutoScaling service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateTableReplicaAutoScalingOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateTableReplicaAutoScalingInput
 @see AWSDynamoDBUpdateTableReplicaAutoScalingOutput
 */
- (AWSTask<AWSDynamoDBUpdateTableReplicaAutoScalingOutput *> *)updateTableReplicaAutoScaling:(AWSDynamoDBUpdateTableReplicaAutoScalingInput *)request;

/**
 <p>Updates auto scaling settings on your global tables at once.</p><important><p>This operation only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21 (Current)</a> of global tables. </p></important>
 
 @param request A container for the necessary parameters to execute the UpdateTableReplicaAutoScaling service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateTableReplicaAutoScalingInput
 @see AWSDynamoDBUpdateTableReplicaAutoScalingOutput
 */
- (void)updateTableReplicaAutoScaling:(AWSDynamoDBUpdateTableReplicaAutoScalingInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateTableReplicaAutoScalingOutput * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 <p>The <code>UpdateTimeToLive</code> method enables or disables Time to Live (TTL) for the specified table. A successful <code>UpdateTimeToLive</code> call returns the current <code>TimeToLiveSpecification</code>. It can take up to one hour for the change to fully process. Any additional <code>UpdateTimeToLive</code> calls for the same table during this one hour duration result in a <code>ValidationException</code>. </p><p>TTL compares the current time in epoch time format to the time stored in the TTL attribute of an item. If the epoch time value stored in the attribute is less than the current time, the item is marked as expired and subsequently deleted.</p><note><p> The epoch time format is the number of seconds elapsed since 12:00:00 AM January 1, 1970 UTC. </p></note><p>DynamoDB deletes expired items on a best-effort basis to ensure availability of throughput for other data operations. </p><important><p>DynamoDB typically deletes expired items within two days of expiration. The exact duration within which an item gets deleted after expiration is specific to the nature of the workload. Items that have expired and not been deleted will still show up in reads, queries, and scans.</p></important><p>As items are deleted, they are removed from any local secondary index and global secondary index immediately in the same eventually consistent way as a standard delete operation.</p><p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/TTL.html">Time To Live</a> in the Amazon DynamoDB Developer Guide. </p>
 
 @param request A container for the necessary parameters to execute the UpdateTimeToLive service method.

 @return An instance of `AWSTask`. On successful execution, `task.result` will contain an instance of `AWSDynamoDBUpdateTimeToLiveOutput`. On failed execution, `task.error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateTimeToLiveInput
 @see AWSDynamoDBUpdateTimeToLiveOutput
 */
- (AWSTask<AWSDynamoDBUpdateTimeToLiveOutput *> *)updateTimeToLive:(AWSDynamoDBUpdateTimeToLiveInput *)request;

/**
 <p>The <code>UpdateTimeToLive</code> method enables or disables Time to Live (TTL) for the specified table. A successful <code>UpdateTimeToLive</code> call returns the current <code>TimeToLiveSpecification</code>. It can take up to one hour for the change to fully process. Any additional <code>UpdateTimeToLive</code> calls for the same table during this one hour duration result in a <code>ValidationException</code>. </p><p>TTL compares the current time in epoch time format to the time stored in the TTL attribute of an item. If the epoch time value stored in the attribute is less than the current time, the item is marked as expired and subsequently deleted.</p><note><p> The epoch time format is the number of seconds elapsed since 12:00:00 AM January 1, 1970 UTC. </p></note><p>DynamoDB deletes expired items on a best-effort basis to ensure availability of throughput for other data operations. </p><important><p>DynamoDB typically deletes expired items within two days of expiration. The exact duration within which an item gets deleted after expiration is specific to the nature of the workload. Items that have expired and not been deleted will still show up in reads, queries, and scans.</p></important><p>As items are deleted, they are removed from any local secondary index and global secondary index immediately in the same eventually consistent way as a standard delete operation.</p><p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/TTL.html">Time To Live</a> in the Amazon DynamoDB Developer Guide. </p>
 
 @param request A container for the necessary parameters to execute the UpdateTimeToLive service method.
 @param completionHandler The completion handler to call when the load request is complete.
                          `response` - A response object, or `nil` if the request failed.
                          `error` - An error object that indicates why the request failed, or `nil` if the request was successful. On failed execution, `error` may contain an `NSError` with `AWSDynamoDBErrorDomain` domain and the following error code: `AWSDynamoDBErrorResourceInUse`, `AWSDynamoDBErrorResourceNotFound`, `AWSDynamoDBErrorLimitExceeded`, `AWSDynamoDBErrorInternalServer`.
 
 @see AWSDynamoDBUpdateTimeToLiveInput
 @see AWSDynamoDBUpdateTimeToLiveOutput
 */
- (void)updateTimeToLive:(AWSDynamoDBUpdateTimeToLiveInput *)request completionHandler:(void (^ _Nullable)(AWSDynamoDBUpdateTimeToLiveOutput * _Nullable response, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
