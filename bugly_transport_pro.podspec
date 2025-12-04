#
#  bugly_transport_pro.podspec
#  Bugly Pro SDK
#
#  Created by Hua Xiang on 2024/03/06.
#

Pod::Spec.new do |s|
    s.name             = 'bugly_transport_pro'
    s.version          = '2.11'
    s.summary          = 'bugly_transport'
    s.homepage         = 'https://github.com/BuglyDevTeam'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'Bugly-Team' => 'hodxiang@tencent.com' }
    s.source           = { :git => 'https://github.com/BuglyDevTeam/bugly-transport-ios.git', :tag => s.version.to_s }

    s.ios.deployment_target = '9.0'
    s.osx.deployment_target = '11.0'

    s.requires_arc     = true
    s.library = 'z', 'c++'
    s.frameworks = 'Foundation', 'SystemConfiguration', 'CoreTelephony'
    s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES' }

    s.vendored_frameworks = 'bugly_transport.xcframework'

  end