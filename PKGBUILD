pkgname="sstring"
pkgver="3.1.1"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("d7205f7145fd7836209b8a56718d9954b7f613eca391dff9b40ea4ac6107f79c57675198fc26e10adc7e899b5d2a079387f3d039a947bdb9c8aa5600515029b8" "f4e77ab36e4614a2fd2f4e0ceaff6a530a4c915db900583f3889171c27ccb4964e956e78d0edb4769076b560738b9e550cfa1c22da2da4904ae0a6948b2daa0d")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
