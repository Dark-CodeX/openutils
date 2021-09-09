pkgname="sstring"
pkgver="5.2.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("a79f371bb6513b06ec579073fa16e46b4c1ebe355a4230ad08a6b86e2b05f0667f8b9c6c2fc329ee659f828f536362a49cdc2eaad5246716ebee01438b593de3" "0de2de0b577ccc9cfa47b277ecf6855f8e7f28ac40faa2eb0ca1cb830ad9abb08819d3959b94480c064d9f3a85f644b39a702b4ff74894bee4925651609eeb42" "785a47707c0bb989d5f84215c496727a283eabbbb25299370fa2c158f5712f68312e04a7c39652b0e937af920f03d1e4ae5308b84efda5ce8cc7f4554201ee12")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
