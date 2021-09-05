pkgname="sstring"
pkgver="3.8.1"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("7c0e7446da71dbedc19f546cb0903f14eb1a1ad8d658fc70b03b95fc441d27762732186a6c31ed722f70b336b44ce6e58fb73de71234d2b9de6447412dc869b0" "e42d68f32350c9c71778992d222ba522f3158969311e5d0a3050b08623437a674ddf0550e194cbaa2b6a04bc9ddc2b92023df4c39727cf52afc494a198c1f587")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
