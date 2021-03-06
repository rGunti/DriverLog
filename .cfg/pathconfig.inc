<?php
return [
    "/" => new HomeRequest(),
    "/Debug" => new DebugViewRequest(),
    "/Debug/PhpInfo" => new PhpInfoRequest(),

    "/Login" => new LoginRequest(),
    "/Logout" => new LoginRequest(),

    "/_Docs" => new AppDocumentRequest(),
    "/_Docs/ToS" => new AppDocumentRequest(),
    "/_Docs/Imprint" => new AppDocumentRequest(),
    "/_Docs/Copyright" => new AppDocumentRequest(),

    "/MySettings" => new UserSettingsRequest(),

    "/AdminTools" => new PageNotFoundRequest(),
    "/AdminTools/Users" => new UserManagerRequest(),

    // AJAX Requests
    "/AJAX/Users" => new AjaxUserRequest(),
];
