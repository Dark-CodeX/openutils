pkgname="sstring"
pkgver="32.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("b1106eb73cfd4e64e0688207abce477d6c405f011e63d211b88234a8e4be7e75547814b8c08ae8746be649dd2cfdbda2c4478623d81451b9bfd6e8c25e08e3c8" "be1ab0a91f1280a7750deb2e9a3c096183ade8e43e143ce629b5d076e1139126b29ad51061ff010df5e6ea3223acc8265eb3fb6190172b2dfbb4e80817d137a2" "e12b355a7711498731a5a32c336e445f3ee86dec63bebde2beb5dd67ba697ed94e2fafe9c714a9e53cdb9015126c423c893f64d14d7327a2431906ec67b19d0f" "ab6eebefaa04941e62742268adb8e2453d23f42c94e76a157777b8bedc627f7eff6d0fefa5233b11df7c84c2e5e1afc32a1c027447dad3aea0913cd2cfb8acf5")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
