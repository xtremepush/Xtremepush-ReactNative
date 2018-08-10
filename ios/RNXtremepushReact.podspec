
Pod::Spec.new do |s|
  s.name         = "RNXtremepushReact"
  s.version      = "1.0.0"
  s.summary      = "RNXtremepushReact"
  s.description  = <<-DESC
                  RNXtremepushReact
                   DESC
  s.homepage     = ""
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/author/RNXtremepushReact.git", :tag => "master" }
  s.source_files  = "RNXtremepushReact/**/*.{h,m}"
  s.requires_arc = true


  s.dependency "React"
  s.dependency "Xtremepush-iOS-SDK"
  #s.dependency "others"

end

  